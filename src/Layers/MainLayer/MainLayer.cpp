
#include <Renderer/Renderer.h>
#include "MainLayer.h"

void MainLayer::onAttach()
{
    std::cout << "Attach";
    std::vector<unsigned int> indices = {
            0,1,2,
            1,2,3,
            4,5,6,
            5,6,7,
            0,1,5,
            0,4,5,
            2,3,7,
            2,6,7,
            0,2,6,
            0,4,6,
            1,5,7,
            1,3,7
    };

    std::vector<float> vertices = {
            -0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,

            -0.5f, -0.5f,  0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f, -0.5f,  0.5f,

            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,

            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,

            -0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f, -0.5f,  0.5f,
            -0.5f, -0.5f,  0.5f,
            -0.5f, -0.5f, -0.5f,

            -0.5f,  0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f
    };

    m_Mesh = Mesh(vertices, indices);

    m_Shader = Shader("C:\\Users\\MBDambo\\Desktop\\Voxel Game\\Voxel-Game\\src\\Shaders\\vertex.shader",
                           "C:\\Users\\MBDambo\\Desktop\\Voxel Game\\Voxel-Game\\src\\Shaders\\fragment.shader");

    m_Camera = Camera(m_Shader);
}

void MainLayer::onDetach()
{
    std::cout << "Detach";
}

void MainLayer::onEvent(Event &event)
{
    std::cout << event.toString();
}

void MainLayer::onUpdate(float deltaTime)
{
    Renderer::prepare();

    m_Shader.use();

    Renderer::render(&m_Mesh, &m_Camera);
}
