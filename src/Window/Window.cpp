//
// Created by MatheusBD on 27/11/2021.
//

#include <VAO/VAO.h>
#include "Window/Window.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"

Window::Window()
{
    m_Window = glfwCreateWindow(1200, 720, "Voxel Game", NULL, NULL);

    if (m_Window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    std::cout << "Window created with success" << std::endl;
}

void Window::start()
{
    glfwMakeContextCurrent(m_Window);

    glfwSwapInterval(GLFW_TRUE);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    std::cout << "Glad created with success" << std::endl;

    glViewport(0, 0, 1200, 720);
    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetWindowUserPointer(m_Window, &m_Data);

    // for seeing wireframe
//     glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    Window::setGLFWCallbacks();
}

void Window::close()
{
    glfwSetWindowShouldClose(m_Window, true);
    glfwDestroyWindow(m_Window);
}

void Window::processInput(float deltaTime)
{
    if(glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_Window, true);
}

void Window::update(float deltaTime)
{
    Window::processInput(deltaTime);
}

void Window::postUpdate()
{
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

void Window::setGLFWCallbacks()
{
    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {

        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        data.width = width;
        data.height = height;

        WindowResizeEvent event(width, height);
        data.eventCallback(event);
    });

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {

        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        WindowCloseEvent event;

        data.eventCallback(event);
    });

    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        switch(action)
        {
            case GLFW_PRESS:
            {
                KeyPressedEvent event(key, 0);
                data.eventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyReleasedEvent event(key);
                data.eventCallback(event);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyPressedEvent event(key, 1);
                data.eventCallback(event);
                break;
            }
            default:
                break;
        }
    });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {

        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        switch(action)
        {
            case GLFW_PRESS:
            {
                MouseButtonPressedEvent event(button);
                data.eventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                MouseButtonReleasedEvent event(button);
                data.eventCallback(event);
                break;
            }
            default:
                break;
        }
    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {

        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        MouseMovedEvent event(xPos, yPos);

        data.eventCallback(event);
    });
}

void Window::mouseCallback(GLFWwindow *window, double xpos, double ypos)
{

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}