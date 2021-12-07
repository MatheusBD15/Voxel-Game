//
// Created by MatheusBD on 27/11/2021.
//

#include <VAO/VAO.h>
#include <Mesh/Mesh.h>
#include "Window.h"

Window::Window()
{
    m_window = glfwCreateWindow(800, 600, "Voxel Game", NULL, NULL);

    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
}

void Window::start()
{
    glfwMakeContextCurrent(m_window);

    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glViewport(0, 0, 800, 600);
    glEnable(GL_DEPTH_TEST);
}

void Window::close()
{
    glfwSetWindowShouldClose(m_window, true);
    glfwDestroyWindow(m_window);
}

void Window::processInput()
{
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window, true);
}

void Window::update()
{
    Window::processInput();
}

void Window::postUpdate()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
