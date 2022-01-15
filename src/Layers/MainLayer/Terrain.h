//
// Created by MBDambo on 15/01/2022.
//

#ifndef VOXELGAME_TERRAIN_H
#define VOXELGAME_TERRAIN_H


#include <vector>
#include <glm/vec2.hpp>
#include <Utils/Vertex.h>

namespace Terrain
{
    std::pair<std::vector<int>, glm::vec2> newHeightMap(glm::vec2& position, int width, float step);

    std::vector<Vertex> newTerrain(std::pair<std::vector<int>, glm::vec2>& heightMap, int width);
}



#endif //VOXELGAME_TERRAIN_H
