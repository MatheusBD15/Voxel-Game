//
// Created by MatheusBD on 28/11/2021.
//

#include <vector>
#include <Mesh/Mesh.h>
#include <Shader/Shader.h>
#include "Application.h"
#include "Renderer/Renderer.h"

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

    std::vector<unsigned int> indices = {  // note that we start from 0!
            0, 1, 3,  // first Triangle
            1, 2, 3   // second Triangle
    };

    std::vector<float> vertices = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left
    };

    Mesh* mesh = new Mesh(vertices, indices);

    Shader shader = Shader("C:\\Users\\MBDambo\\Desktop\\Voxel Game\\Voxel-Game\\src\\Shaders\\vertex.shader",
                           "C:\\Users\\MBDambo\\Desktop\\Voxel Game\\Voxel-Game\\src\\Shaders\\fragment.shader");

    while(m_running)
    {
        m_window->update();

        Renderer::prepare();

        shader.use();

        Renderer::render(mesh);

        m_window->postUpdate();

        if(glfwWindowShouldClose(m_window->getWindow()))
        {
            m_running = false;
        }
    }

    delete(mesh);

    glfwTerminate();
}
