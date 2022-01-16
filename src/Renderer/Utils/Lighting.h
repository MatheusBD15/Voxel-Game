//
// Created by MBDambo on 15/01/2022.
//

#ifndef VOXELGAME_LIGHTING_H
#define VOXELGAME_LIGHTING_H

#include <glm/vec3.hpp>

struct Lighting
{
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
};

struct Material : public Lighting
{
    float shininess;
};

#endif //VOXELGAME_LIGHTING_H
