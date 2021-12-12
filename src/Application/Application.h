//
// Created by MatheusBD on 28/11/2021.
//

#ifndef VOXELGAME_APPLICATION_H
#define VOXELGAME_APPLICATION_H

#include <ApplicationEvent.h>
#include "Window.h"

class Application
{
private:
    Window* m_Window;
    bool m_Running = true;
    float m_DeltaTime = 0.0f;
    float m_LastFrame = 0.0f;

public:
    Application();

    void run();

    void onEvent(Event& event);

    bool onWindowClose(WindowCloseEvent& e);
};


#endif //VOXELGAME_APPLICATION_H
