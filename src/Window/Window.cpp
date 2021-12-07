//
// Created by MatheusBD on 27/11/2021.
//

#include <VAO/VAO.h>
#include <Mesh/Mesh.h>
#include "Window.h"
#include "Application.h"

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
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(m_window, [this](GLFWwindow *window, double xpos, double ypos) {mouseCallback(window, xpos, ypos;}));
}

void Window::close()
{
    glfwSetWindowShouldClose(m_window, true);
    glfwDestroyWindow(m_window);
}

void Window::processInput(float deltaTime)
{
    const float cameraSpeed = 2.5f * deltaTime; // adjust accordingly

    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window, true);
    if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
        m_camera->m_cameraPos += cameraSpeed * m_camera->m_cameraFront;
    if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
        m_camera->m_cameraPos -= cameraSpeed * m_camera->m_cameraFront;
    if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
        m_camera->m_cameraPos -= glm::normalize(glm::cross(m_camera->m_cameraFront, m_camera->m_cameraUp)) * cameraSpeed;
    if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
        m_camera->m_cameraPos += glm::normalize(glm::cross(m_camera->m_cameraFront, m_camera->m_cameraUp)) * cameraSpeed;
}

void Window::update(float deltaTime)
{
    Window::processInput(deltaTime);
}

void Window::setCamera(Camera *camera)
{
    m_camera = camera;
}

void Window::postUpdate()
{
    glfwSwapBuffers(m_window);
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
//    float xoffset = xpos - Camera::m_lastX;
//    float yoffset = Camera::m_lastY - ypos; // reversed since y-coordinates range from bottom to top
//    Camera::m_lastX = xpos;
//    Camera::m_lastY = ypos;
//
//    xoffset *= Camera::m_sensitivity;
//    yoffset *= Camera::m_sensitivity;
//
//    Camera::m_yaw   += xoffset;
//    Camera::m_pitch += yoffset;
//
//    if(Camera::m_pitch > 89.0f)
//        Camera::m_pitch =  89.0f;
//    if(Camera::m_pitch < -89.0f)
//        Camera::m_pitch = -89.0f;
}
