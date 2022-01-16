//
// Created by MBDambo on 15/01/2022.
//

#ifndef VOXELGAME_CHUNK_H
#define VOXELGAME_CHUNK_H


#include <utility>
#include <glm/vec2.hpp>
#include <vector>
#include <Shader/Shader.h>
#include <Utils/Lighting.h>
#include <Mesh/RenderableMesh.h>
#include "Terrain.h"

#define DEFAULT_VERT "C:\\Users\\MBDambo\\Desktop\\Voxel Game\\Voxel-Game\\src\\Shaders\\defaultVertex.shader"
#define DEFAULT_FRAG "C:\\Users\\MBDambo\\Desktop\\Voxel Game\\Voxel-Game\\src\\Shaders\\defaultFrag.shader"

class Chunk
{
public:
    Chunk() = default;

    Chunk(glm::vec2 position, Material material);

public:

    void Prepare(glm::vec3& ligthPos, Lighting& aspects, glm::vec3 cameraPos);

    inline RenderableMesh& GetRenderable()
    {
        return m_Renderable;
    }

private:
    std::pair<std::vector<int>, glm::vec2> m_Heights;
    glm::vec2 m_Position;

    Material m_Material;
    RenderableMesh m_Renderable;
};



#endif //VOXELGAME_CHUNK_H
