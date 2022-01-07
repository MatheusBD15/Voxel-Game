//
// Created by MBDambo on 03/01/2022.
//

#ifndef VOXELGAME_VERTEX_H
#define VOXELGAME_VERTEX_H

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <array>
#include <iostream>

struct Vertex
{
    glm::vec3 position;
    glm::vec4 color;
    glm::vec3 normal;

    friend inline bool operator== (const Vertex& vertex1, const Vertex& vertex2)
    {
        return vertex1.position == vertex2.position && vertex1.normal == vertex2.normal;
    }
};

#endif //VOXELGAME_VERTEX_H
