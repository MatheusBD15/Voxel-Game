//
// Created by MBDambo on 07/12/2021.
//

#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 target, float fov)
    : m_Position(std::move(position))
    , m_Target(std::move(target))
    , m_Fov(fov)
{
    glm::vec3 dir = glm::normalize(m_Target - m_Position);
    m_Pitch = glm::degrees(asin(dir.y));
    m_Yaw = glm::degrees(atan2(dir.z, dir.x));

    m_Projection = glm::perspective(glm::radians(fov), (float)1200 / (float)720, 0.1f, 1500.0f);
    UpdateVectors();
}

void Camera::UpdateVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    front.y = sin(glm::radians(m_Pitch));
    front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_Target = glm::normalize(front);

    m_Right = glm::normalize(glm::cross(m_Target, glm::vec3(0.0f, 1.0f, 0.0f)));
    m_Up = glm::normalize(glm::cross(m_Right, m_Target));
}

void Camera::UpdateMouse(MouseMovedEvent &event)
{
    double xPos;
    double yPos;

    if (m_FirstMouse)
    {
        m_LastX = event.getX();
        m_LastY = event.getY();
        m_FirstMouse = false;
    }

    float xoffset = event.getX() - m_LastX;
    float yoffset = m_LastY - event.getY(); // Invertido pois o Y é ao contrário no GLFW

    m_LastX = event.getX();
    m_LastY = event.getY();

    xoffset *= m_Sensitivity;
    yoffset *= m_Sensitivity;

    m_Yaw += xoffset;
    m_Pitch += yoffset;

    if (m_Pitch > 89.0f)
        m_Pitch = 89.0f;
    if (m_Pitch < -89.0f)
        m_Pitch = -89.0f;

    UpdateVectors();
}

void Camera::UpdateKeyboard(KeyPressedEvent &event, float dt)
{
    const float cameraSpeed = 200.0f * dt; // adjust accordingly

    // w key was pressed
    if(event.getKeyCode() == 87)
    {
        m_Position += cameraSpeed * m_Target;
    }
    // s key
    if(event.getKeyCode() == 83)
    {
        m_Position -= cameraSpeed * m_Target;
    }
    // a key
    if(event.getKeyCode() == 65)
    {
        m_Position -= glm::normalize(glm::cross(m_Target, m_Up)) * cameraSpeed;
    }
    // d key
    if(event.getKeyCode() == 68)
    {
        m_Position += glm::normalize(glm::cross(m_Target, m_Up)) * cameraSpeed;
    }
}

