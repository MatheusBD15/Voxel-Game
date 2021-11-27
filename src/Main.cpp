//
// Created by MatheusBD on 26/11/2021.
//
#include "Main.h"
#include <glad/glad.h>
#include "Window/Window.h"

int main()
{
    Window* window = new Window();

    window->start();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
