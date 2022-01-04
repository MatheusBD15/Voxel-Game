//
// Created by MBDambo on 07/12/2021.
//

#ifndef VOXELGAME_CAMERA_H
#define VOXELGAME_CAMERA_H

#include <glm/ext/matrix_float4x4.hpp>
#include <Shader/Shader.h>
#include <GLFW/glfw3.h>

class Camera {
public:

    bool m_FirstMouse = true;
    // View matrices
    glm::mat4 m_Model;
    glm::mat4 m_View;
    glm::mat4 m_Projection;

    // position vectors
    glm::vec3 m_CameraPos = glm::vec3(0.0f, 5.0f, 10.0f);
    glm::vec3 m_CameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::vec3 m_CameraFront;

    glm::vec3 m_WorldUp;

    glm::vec3 m_CameraDirection;
    glm::vec3 m_CameraRight;

    // variables for mouse movement
    float m_Yaw = -90.0f;
    float m_Pitch = 0.0f;
    float m_LastX = 400, m_lastY = 300;
    float m_Sensitivity = 0.1f;

    // vertex shader that belongs to the camera
    Shader m_VertexShader;

public:
    Camera();

    void setVertexShader(const Shader &vertexShader);

    void updateCameraVectors();

    // sets the uniforms
    void use();
};


#endif //VOXELGAME_CAMERA_H
