//
// Created by MatheusBD on 28/11/2021.
//

#ifndef VOXELGAME_APPLICATION_H
#define VOXELGAME_APPLICATION_H

#include <Events/ApplicationEvent.h>
#include <Events/KeyEvent.h>
#include <Events/MouseEvent.h>
#include <Layers/Layer.h>
#include <Layers/LayerStack.h>
#include "Window/Window.h"

class Application
{
private:
    Window* m_Window;
    bool m_Running = true;
    float m_DeltaTime = 0.0f;
    float m_LastFrame = 0.0f;
    LayerStack m_LayerStack;

public:
    Application();

    void run();

    // layer handling
    void pushLayer(Layer* layer);
    void pushOverlay(Layer* overlay);
    void onEvent(Event& event);

    // event callbacks
    bool onWindowClose(WindowCloseEvent& e);
};


#endif //VOXELGAME_APPLICATION_H
