//
// Created by MBDambo on 07/12/2021.
//

#include "Camera.h"

Camera::Camera(const Shader& vertexShader)
{
    m_vertexShader = vertexShader;

    m_model = glm::mat4(1.0f);
    m_model = glm::rotate(m_model, glm::radians(10.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    m_view = glm::mat4(1.0f);
    m_view = glm::translate(m_view, glm::vec3(0.0f, 0.0f, -3.0f));

    m_projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

void Camera::use()
{
    m_model = glm::rotate(m_model, (float)glfwGetTime() * glm::radians(0.1f), glm::vec3(0.5f, 1.0f, 0.0f));
    m_vertexShader.setUniform("model", m_model);
    m_vertexShader.setUniform("view", m_view);
    m_vertexShader.setUniform("projection", m_projection);
}
