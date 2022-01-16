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
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec3 Color;

    Vertex()
            : Position(glm::vec3(0.0f))
            , Normal(glm::vec3(0.0f))
            , Color(glm::vec3(0.0f))
    {}

    Vertex(glm::vec3 position, glm::vec3 normal, glm::vec3 color)
            : Position(position)
            , Normal(normal)
            , Color(color)
    {}

    Vertex(
           float posX, float posY, float posZ,
           float normalX, float normalY, float normalZ,
           float colorR, float colorG, float colorB
    )
            : Position(glm::vec3(posX, posY, posZ))
            , Normal(glm::vec3(normalX, normalY, normalZ))
            , Color(glm::vec3(colorR, colorG, colorB))
    {}
};


#endif //VOXELGAME_VERTEX_H
