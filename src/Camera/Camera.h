//
// Created by MBDambo on 07/12/2021.
//

#ifndef VOXELGAME_CAMERA_H
#define VOXELGAME_CAMERA_H

#include <glm/ext/matrix_float4x4.hpp>
#include <Shader/Shader.h>
#include <GLFW/glfw3.h>

class Camera {
private:
    glm::mat4 m_model;
    glm::mat4 m_view;
    glm::mat4 m_projection;
    Shader m_vertexShader;

public:
    Camera(const Shader &vertexShader);

    // sets the uniforms
    void use();
};


#endif //VOXELGAME_CAMERA_H
