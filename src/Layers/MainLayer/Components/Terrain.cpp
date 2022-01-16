//
// Created by MBDambo on 15/01/2022.
//

#include "Terrain.h"
#include "Layers/MainLayer/Noise/Noise.h"

#define FLAT(i, j, width) i * width + j


std::pair<std::vector<int>, glm::vec2> Terrain::newHeightMap(glm::vec2& position, int width, float step)
{
    std::vector<int> heights(width * width);

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < width; ++i)
        for (int j = 0; j < width; ++j)
        {
            int height = int(Noise::cleanf(Noise::noise2df(
                    position.x + (step * i),
                    position.y + (step * j)
            )));
            heights[FLAT(i, j, width)] = height;

            if (height > max) max = height;
            if (height < min) min = height;
        }

    return { heights, glm::vec2(max, min) };
}


std::vector<Vertex> Terrain::newTerrain(std::pair<std::vector<int>, glm::vec2>& heightMap, int width)
{
    auto& [ heights, limits ] = heightMap;

    // Gets maximum and minimum values
    int max = int(limits.x);
    int min = int(limits.y);

    std::vector<std::vector<std::pair<std::pair<int, int>, int>>> processedHeights;

    // auto comp = [](float a, float b) -> bool { return (std::abs(a - b) < DELTA_M); };

    for (int pass = min; pass <= max; ++pass)
    {
        std::vector<std::pair<std::pair<int, int>, int>> terrainLevel;

        for (int i = 0; i < width; ++i)
            for (int j = 0; j < width; ++j)
            {
                int height = heights[FLAT(i, j, width)];

                if (pass == height) {
                    terrainLevel.push_back({ { i, j }, pass });
                }
            }

        processedHeights.push_back(terrainLevel);
    }

    enum FaceType
    {
        Z_ALIGNED,
        Y_ALIGNED,
        X_ALIGNED,
    };

#define FACE_NORMAL 1
#define FACE_INVERSE (-1)

    auto getQuad = [](glm::vec2 v1, glm::vec2 v2, float height, int face, FaceType type) -> std::vector<Vertex>
    {
        switch (type)
        {
            case Z_ALIGNED:
                return std::vector<Vertex> {
                        { v1.x, v2.y, height,  0.0f, 0.0f, float(face) * 1.0f,  1.0f, 1.0f, 1.0f },
                        { v1.x, v1.y, height,  0.0f, 0.0f, float(face) * 1.0f,  1.0f, 1.0f, 1.0f },
                        { v2.x, v2.y, height,  0.0f, 0.0f, float(face) * 1.0f,  1.0f, 1.0f, 1.0f },
                        { v2.x, v2.y, height,  0.0f, 0.0f, float(face) * 1.0f,  1.0f, 1.0f, 1.0f },
                        { v1.x, v1.y, height,  0.0f, 0.0f, float(face) * 1.0f,  1.0f, 1.0f, 1.0f },
                        { v2.x, v1.y, height,  0.0f, 0.0f, float(face) * 1.0f,  1.0f, 1.0f, 1.0f },
                };
                break;
            case Y_ALIGNED:
                return std::vector<Vertex> {
                        { v1.x, height, v2.y,  0.0f, float(face) * 1.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                        { v1.x, height, v1.y,  0.0f, float(face) * 1.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                        { v2.x, height, v2.y,  0.0f, float(face) * 1.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                        { v2.x, height, v2.y,  0.0f, float(face) * 1.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                        { v1.x, height, v1.y,  0.0f, float(face) * 1.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                        { v2.x, height, v1.y,  0.0f, float(face) * 1.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                };
                break;
            case X_ALIGNED:
                return std::vector<Vertex> {
                        { height, v1.x, v2.y,  float(face) * 1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                        { height, v1.x, v1.y,  float(face) * 1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                        { height, v2.x, v2.y,  float(face) * 1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                        { height, v2.x, v2.y,  float(face) * 1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                        { height, v1.x, v1.y,  float(face) * 1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                        { height, v2.x, v1.y,  float(face) * 1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 1.0f },
                };
                break;
        }
        return std::vector<Vertex>{};
    };

    std::vector<Vertex> terrainVertex;

    // At least number of cell in quads
    terrainVertex.reserve(width * width * 6);

    // To find neighbors
    int offsetX[4] = { 0,  0,  1, -1 };
    int offsetZ[4] = { 1, -1,  0,  0 };

    for (auto& level : processedHeights)
    {
        for (auto& abstractQuad : level)
        {
            auto& [ baseXZ, baseY ] = abstractQuad;
            auto& [ baseX, baseZ ] = baseXZ;

            // Calculates base planar quad
            std::vector<Vertex> quad = getQuad(
                    glm::vec2(baseX, baseZ),
                    glm::vec2(baseX + 1, baseZ + 1),
                    baseY, FACE_NORMAL, Y_ALIGNED
            );

            terrainVertex.insert(terrainVertex.end(), quad.begin(), quad.end());

            for (int i = 0; i < 4; ++i)
            {
                int nx = baseX + offsetX[i];
                int ny = baseZ + offsetZ[i];

                if (nx < 0 || nx >= width || ny < 0 || ny >= width)
                    continue;

                int neighbourY = heights[FLAT(nx, ny, width)];

                if (neighbourY > baseY)
                {
                    const int offsetY = neighbourY - baseY;

                    if (i == 0)
                    {
                        std::vector<Vertex> vertQuad = getQuad(
                                glm::vec2(baseX, baseY),
                                glm::vec2(baseX + 1, baseY + offsetY),
                                baseZ + 1, FACE_INVERSE, Z_ALIGNED
                        );
                        terrainVertex.insert(terrainVertex.end(), vertQuad.begin(), vertQuad.end());
                    }
                    if (i == 1)
                    {
                        std::vector<Vertex> vertQuad = getQuad(
                                glm::vec2(baseX + 1, baseY),
                                glm::vec2(baseX, baseY + offsetY),
                                baseZ, FACE_NORMAL, Z_ALIGNED
                        );
                        terrainVertex.insert(terrainVertex.end(), vertQuad.begin(), vertQuad.end());
                    }
                    if (i == 2)
                    {
                        std::vector<Vertex> vertQuad = getQuad(
                                glm::vec2(baseY, baseZ),
                                glm::vec2(baseY + offsetY, baseZ + 1),
                                baseX + 1, FACE_INVERSE, X_ALIGNED
                        );
                        terrainVertex.insert(terrainVertex.end(), vertQuad.begin(), vertQuad.end());
                    }
                    if (i == 3)
                    {
                        std::vector<Vertex> vertQuad = getQuad(
                                glm::vec2(baseY, baseZ + 1),
                                glm::vec2(baseY + offsetY, baseZ),
                                baseX, FACE_NORMAL, X_ALIGNED
                        );
                        terrainVertex.insert(terrainVertex.end(), vertQuad.begin(), vertQuad.end());
                    }
                }
            }
        }
    }

    return terrainVertex;
}
