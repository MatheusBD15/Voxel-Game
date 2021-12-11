//
// Created by MatheusBD on 27/11/2021.
//

#include <VAO/VAO.h>
#include <Mesh/Mesh.h>
#include "Window.h"
#include "Application.h"

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
    glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    //glfwSetCursorPosCallback(m_Window, [this](GLFWwindow *window, double xpos, double ypos) {mouseCallback(window, xpos, ypos;}));
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
