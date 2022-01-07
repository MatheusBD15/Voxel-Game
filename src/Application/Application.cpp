//
// Created by MatheusBD on 28/11/2021.
//

#include <vector>
#include <Mesh/Mesh.h>
#include <Shader/Shader.h>
#include <Camera/Camera.h>
#include <Layers/MainLayer/MainLayer.h>
#include "Application.h"

#define EVENT_FUNCTION(function) [this](auto&&... args) -> decltype(auto) { return this->function(std::forward<decltype(args)>(args)...); }

Application::Application()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = new Window();
    m_Window->setEventCallback(EVENT_FUNCTION(Application::onEvent));
    m_LayerStack = LayerStack();
    Application::pushLayer(new MainLayer());
};

void Application::run()
{
    m_Window->start();

    // runs all onAttach of all layers
    for(Layer* layer : m_LayerStack)
        layer->onAttach();

    std::cout << "Layers attached" << std::endl;

    while(m_Running)
    {
        // delta time calculation
        float currentFrame = glfwGetTime();
        m_DeltaTime = currentFrame - m_LastFrame;
        m_LastFrame = currentFrame;

        m_Window->update(m_DeltaTime);

        for(Layer* layer : m_LayerStack)
            layer->onUpdate(m_DeltaTime);

        m_Window->postUpdate();

        if(glfwWindowShouldClose(m_Window->getWindow()))
        {
            m_Running = false;
        }
    }

    glfwTerminate();
}

void Application::onEvent(Event &event)
{
    EventDispatcher dispatcher(event);

    dispatcher.dispatch<WindowCloseEvent>(EVENT_FUNCTION(Application::onWindowClose));

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
