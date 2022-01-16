//
// Created by MBDambo on 07/12/2021.
//

#ifndef VOXELGAME_CAMERA_H
#define VOXELGAME_CAMERA_H

#include <glm/ext/matrix_float4x4.hpp>
#include <Shader/Shader.h>
#include <GLFW/glfw3.h>
#include <Events/MouseEvent.h>
#include <Events/KeyEvent.h>

class Camera {

private:
    glm::mat4 m_View;
    glm::mat4 m_Projection;

    glm::vec3 m_Position;
    glm::vec3 m_Target;
    glm::vec3 m_Right;
    glm::vec3 m_Up;

    float m_Yaw = 0.0f;
    float m_Pitch = 0.0f;

    float m_Fov = 60.0f;

    float m_Speed = 8.0f;
    float m_Sensitivity = 0.1f;

    float m_LastX = 1200 / 2.0f;
    float m_LastY = 720 / 2.0f;
    bool m_FirstMouse = true;

public:
    Camera(glm::vec3 position, glm::vec3 target, float fov);

    inline glm::mat4 GetView() const
    {
        return glm::lookAt(m_Position, m_Position + m_Target, m_Up);
    }

    inline glm::mat4 GetProjection() const
    {
        return m_Projection;
    }

    inline glm::vec3 GetPosition() const
    {
        return m_Position;
    }

    void UpdateMouse(MouseMovedEvent &event);

    void UpdateKeyboard(KeyPressedEvent& event, float dt);

private:
    void UpdateVectors();
};


#endif //VOXELGAME_CAMERA_H
