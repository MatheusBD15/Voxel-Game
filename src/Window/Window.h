//
// Created by MatheusBD on 27/11/2021.
//

#ifndef VOXELGAME_WINDOW_H
#define VOXELGAME_WINDOW_H

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include <Camera.h>

class Window
{
private:
    GLFWwindow* m_Window;
    Camera* m_Camera;

public:

    Window();

    void start();

    void close();

    void update(float deltaTime);

    void postUpdate();

    GLFWwindow* getWindow() { return m_Window; };

    void processInput(float deltaTime);

    void setCamera(Camera* camera);

    void mouseCallback(GLFWwindow* window, double xpos, double ypos);
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void mouseCallback(GLFWwindow* window, double xpos, double ypos);



#endif //VOXELGAME_WINDOW_H
