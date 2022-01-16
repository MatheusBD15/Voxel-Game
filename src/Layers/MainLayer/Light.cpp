//
// Created by MBDambo on 15/01/2022.
//

#include "Light.h"

void Light::Prepare()
{
    Shader& shader = m_Renderable.GetShader();
    shader.use();

    shader.setUniform("uModel", glm::translate(glm::mat4(1.0f), m_Position));

    shader.unUse();
}

