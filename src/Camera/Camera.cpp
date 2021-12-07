//
// Created by MBDambo on 07/12/2021.
//

#include "Camera.h"

Camera::Camera(const Shader& vertexShader)
{
    m_vertexShader = vertexShader;

    m_cameraDirection.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_cameraDirection.y = sin(glm::radians(m_pitch));
    m_cameraDirection.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_cameraFront = glm::normalize(m_cameraDirection);

    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    m_cameraRight = glm::normalize(glm::cross(up, m_cameraDirection));

    m_cameraUp = glm::cross(m_cameraDirection, m_cameraRight);

    m_model = glm::mat4(1.0f);
    m_model = glm::rotate(m_model, glm::radians(10.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    m_view = glm::mat4(1.0f);
    m_view = glm::lookAt(m_cameraPos, m_cameraPos + m_cameraFront, m_cameraUp);

    m_projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

void Camera::use()
{
    // update camera rotation
    m_cameraDirection.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_cameraDirection.y = sin(glm::radians(m_pitch));
    m_cameraDirection.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_cameraFront = glm::normalize(m_cameraDirection);

    // update view
    m_view = glm::lookAt(m_cameraPos, m_cameraPos + m_cameraFront, m_cameraUp);

    m_vertexShader.setUniform("model", m_model);
    m_vertexShader.setUniform("view", m_view);
    m_vertexShader.setUniform("projection", m_projection);
}
