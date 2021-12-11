//
// Created by MBDambo on 07/12/2021.
//

#include "Camera.h"

Camera::Camera(const Shader& vertexShader)
{
    m_VertexShader = vertexShader;

    m_CameraDirection.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_CameraDirection.y = sin(glm::radians(m_Pitch));
    m_CameraDirection.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_CameraFront = glm::normalize(m_CameraDirection);

    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    m_CameraRight = glm::normalize(glm::cross(up, m_CameraDirection));

    m_CameraUp = glm::cross(m_CameraDirection, m_CameraRight);

    m_Model = glm::mat4(1.0f);
    m_Model = glm::rotate(m_Model, glm::radians(10.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    m_View = glm::mat4(1.0f);
    m_View = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);

    m_Projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

void Camera::use()
{
    // update camera rotation
    m_CameraDirection.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_CameraDirection.y = sin(glm::radians(m_Pitch));
    m_CameraDirection.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_CameraFront = glm::normalize(m_CameraDirection);

    // update view
    m_View = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);

    m_VertexShader.setUniform("model", m_Model);
    m_VertexShader.setUniform("view", m_View);
    m_VertexShader.setUniform("projection", m_Projection);
}
