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

    GLFWwindow* getWindow() { return m_window; };

    static void processInput(GLFWwindow *window);
};

#endif //VOXELGAME_WINDOW_H
