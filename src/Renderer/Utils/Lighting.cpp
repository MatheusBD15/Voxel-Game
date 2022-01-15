//
// Created by MBDambo on 15/01/2022.
//

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


