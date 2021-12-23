//
// Created by MatheusBD on 28/11/2021.
//

#include <vector>
#include <Mesh/Mesh.h>
#include <Shader/Shader.h>
#include <Camera/Camera.h>
#include <Layers/MainLayer/MainLayer.h>
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
    m_LayerStack = LayerStack();
    Application::pushLayer(new MainLayer());
};

void Application::run()
{
    m_Window->start();

    // runs all onAttach of all layers
    for(Layer* layer : m_LayerStack)
        layer->onAttach();

    while(m_Running)
    {
        // delta time calculation
        float currentFrame = glfwGetTime();
        m_DeltaTime = currentFrame - m_LastFrame;
        m_LastFrame = currentFrame;

        m_Window->update(m_DeltaTime);

        for(Layer* layer : m_LayerStack)
            layer->onUpdate(m_DeltaTime);

//        Renderer::prepare();
//
//        shader.use();
//
//        camera.use();
//
//        Renderer::render(&mesh);

        m_Window->postUpdate();

        if(glfwWindowShouldClose(m_Window->getWindow()))
        {
            m_Running = false;
        }
    }

//    delete(&mesh);

    glfwTerminate();
}

void Application::onEvent(Event &event)
{
    EventDispatcher dispatcher(event);

    dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));

    // dispatch events to all layers
    for(auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
    {
        (*--it)->onEvent(event);
        if(event.handled) break;
    }
}

bool Application::onWindowClose(WindowCloseEvent &e)
{
    std::cout << e.toString();
    m_Running = false;
    m_Window->close();
    return true;
}

void Application::pushLayer(Layer *layer)
{
    m_LayerStack.pushLayer(layer);
}

void Application::pushOverlay(Layer *overlay)
{
    m_LayerStack.pushOverlay(overlay);
}
