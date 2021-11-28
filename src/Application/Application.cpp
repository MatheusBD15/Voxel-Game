//
// Created by MatheusBD on 28/11/2021.
//

#include "Application.h"

Application::Application()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = new Window();
};

void Application::run()
{
    m_window->start();
}
