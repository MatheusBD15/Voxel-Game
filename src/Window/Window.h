//
// Created by MatheusBD on 27/11/2021.
//

#ifndef VOXELGAME_WINDOW_H
#define VOXELGAME_WINDOW_H

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

class Window
{
private:
    GLFWwindow* m_window;

public:

    Window();

    void start();

    void close();

    void update();

    void postUpdate();

    GLFWwindow* getWindow() { return m_window; };

    void processInput();
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif //VOXELGAME_WINDOW_H
