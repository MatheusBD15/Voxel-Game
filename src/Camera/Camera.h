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
    // View matrices
    glm::mat4 m_model;
    glm::mat4 m_view;
    glm::mat4 m_projection;

    // position vectors
    glm::vec3 m_cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 m_cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 m_cameraUp = glm::vec3(0.0f, 1.0f,  0.0f);

    glm::vec3 m_cameraFront;

    glm::vec3 m_cameraDirection;
    glm::vec3 m_cameraRight;

    // variables for mouse movement
    float m_yaw = -90.0f;
    float m_pitch = 0.0f;
    float m_lastX = 400, m_lastY = 300;
    float m_sensitivity = 0.1f;

    // vertex shader that belongs to the camera
    Shader m_vertexShader;

public:
    Camera(const Shader &vertexShader);

    // sets the uniforms
    void use();
};


#endif //VOXELGAME_CAMERA_H
