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
    m_Window = glfwCreateWindow(800, 600, "Voxel Game", NULL, NULL);

    if (m_Window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
}

void Window::start()
{
    glfwMakeContextCurrent(m_Window);

    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glViewport(0, 0, 800, 600);
    glEnable(GL_DEPTH_TEST);
//    glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetWindowUserPointer(m_Window, &m_Data);

    Window::setGLFWCallbacks();
}

void Window::close()
{
    glfwSetWindowShouldClose(m_Window, true);
    glfwDestroyWindow(m_Window);
}

void Window::processInput(float deltaTime)
{
    // replace with event generation
    const float cameraSpeed = 2.5f * deltaTime; // adjust accordingly

    if(glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_Window, true);
    if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS)
        m_Camera->m_CameraPos += cameraSpeed * m_Camera->m_CameraFront;
    if (glfwGetKey(m_Window, GLFW_KEY_S) == GLFW_PRESS)
        m_Camera->m_CameraPos -= cameraSpeed * m_Camera->m_CameraFront;
    if (glfwGetKey(m_Window, GLFW_KEY_A) == GLFW_PRESS)
        m_Camera->m_CameraPos -= glm::normalize(glm::cross(m_Camera->m_CameraFront, m_Camera->m_CameraUp)) * cameraSpeed;
    if (glfwGetKey(m_Window, GLFW_KEY_D) == GLFW_PRESS)
        m_Camera->m_CameraPos += glm::normalize(glm::cross(m_Camera->m_CameraFront, m_Camera->m_CameraUp)) * cameraSpeed;
}

void Window::update(float deltaTime)
{
    Window::processInput(deltaTime);
}

void Window::setCamera(Camera *camera)
{
    m_Camera = camera;
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

        std::cout << "AAA";

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

void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
//    float xoffset = xpos - Camera::m_LastX;
//    float yoffset = Camera::m_lastY - ypos; // reversed since y-coordinates range from bottom to top
//    Camera::m_LastX = xpos;
//    Camera::m_lastY = ypos;
//
//    xoffset *= Camera::m_Sensitivity;
//    yoffset *= Camera::m_Sensitivity;
//
//    Camera::m_Yaw   += xoffset;
//    Camera::m_Pitch += yoffset;
//
//    if(Camera::m_Pitch > 89.0f)
//        Camera::m_Pitch =  89.0f;
//    if(Camera::m_Pitch < -89.0f)
//        Camera::m_Pitch = -89.0f;
}
