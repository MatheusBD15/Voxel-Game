//
// Created by MBDambo on 07/12/2021.
//

#include "Camera.h"

Camera::Camera()
{
    m_CameraDirection.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_CameraDirection.y = sin(glm::radians(m_Pitch));
    m_CameraDirection.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_CameraFront = glm::normalize(m_CameraDirection);

    m_WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

    m_CameraRight = glm::normalize(glm::cross(m_WorldUp, m_CameraDirection));

    m_CameraUp = glm::cross(m_CameraDirection, m_CameraRight);

    m_Model = glm::mat4(1.0f);
    m_Model = glm::rotate(m_Model, glm::radians(10.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    m_View = glm::mat4(1.0f);
    m_View = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);

    m_Projection = glm::perspective(glm::radians(45.0f), 1200.0f / 720.0f, 0.1f, 1500.0f);
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

    m_VertexShader.setUniform("viewPos", m_CameraPos);
}

void Camera::setVertexShader(const Shader &vertexShader)
{
    m_VertexShader = vertexShader;
}

void Camera::updateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    front.y = sin(glm::radians(m_Pitch));
    front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_CameraFront = glm::normalize(front);
    m_CameraRight = glm::normalize(glm::cross(m_CameraFront, m_WorldUp));
    m_CameraUp = glm::normalize(glm::cross(m_CameraRight, m_CameraFront));
}
