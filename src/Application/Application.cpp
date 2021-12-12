//
// Created by MatheusBD on 28/11/2021.
//

#include <vector>
#include <Mesh/Mesh.h>
#include <Shader/Shader.h>
#include <Camera.h>
#include "Application.h"
#include "Renderer/Renderer.h"

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

Application::Application()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = new Window();
    m_Window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
};

void Application::run()
{
    std::vector<unsigned int> indices = {  // note that we start from 0!
        // /*Above ABC,BCD*/
        0,1,2,
        1,2,3,
        /*Following EFG,FGH*/
        4,5,6,
        5,6,7,
        /*Left ABF,AEF*/
        0,1,5,
        0,4,5,
        /*Right side CDH,CGH*/
        2,3,7,
        2,6,7,
        /*ACG,AEG*/
        0,2,6,
        0,4,6,
        /*Behind BFH,BDH*/
        1,5,7,
        1,3,7
    };

//    std::vector<float> vertices = {
//        -0.5f,0.5f,-0.5f,   0.0f, 0.0f, 0.0f,//Point A 0
//        -0.5f,0.5f,0.5f,    0.0f, 0.0f, 1.0f,//Point B 1
//        0.5f,0.5f,-0.5f,    0.0f, 1.0f, 0.0f,//Point C 2
//        0.5f,0.5f,0.5f,     0.0f, 1.0f, 1.0f,//Point D 3
//
//        -0.5f,-0.5f,-0.5f,  1.0f, 0.0f, 0.0f,//Point E 4
//        -0.5f,-0.5f,0.5f,   1.0f, 0.0f, 1.0f,//Point F 5
//        0.5f,-0.5f,-0.5f,   1.0f, 1.0f, 0.0f,//Point G 6
//        0.5f,-0.5f,0.5f,    1.0f, 1.0f, 1.0f//Point H 7
//    };

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

    m_Window->start();

    Mesh mesh = Mesh(vertices, indices);

    Shader shader = Shader("C:\\Users\\MBDambo\\Desktop\\Voxel Game\\Voxel-Game\\src\\Shaders\\vertex.shader",
                           "C:\\Users\\MBDambo\\Desktop\\Voxel Game\\Voxel-Game\\src\\Shaders\\fragment.shader");

    Camera camera = Camera(shader);

    m_Window->setCamera(&camera);

    while(m_Running)
    {
        // delta time calculation
        float currentFrame = glfwGetTime();
        m_DeltaTime = currentFrame - m_LastFrame;
        m_LastFrame = currentFrame;

        m_Window->update(m_DeltaTime);

        Renderer::prepare();

        shader.use();

        Renderer::render(&mesh, &camera);

        m_Window->postUpdate();

        if(glfwWindowShouldClose(m_Window->getWindow()))
        {
            m_Running = false;
        }
    }

    delete(&mesh);

    glfwTerminate();
}

void Application::onEvent(Event &event)
{
    std::cout << "AAA";
    EventDispatcher dispatcher(event);

    dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));
}

bool Application::onWindowClose(WindowCloseEvent &e)
{
    m_Running = false;
    m_Window->close();
    return true;
}
