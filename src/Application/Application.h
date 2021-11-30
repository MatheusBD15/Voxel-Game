//
// Created by MatheusBD on 28/11/2021.
//

#ifndef VOXELGAME_APPLICATION_H
#define VOXELGAME_APPLICATION_H

#include "Window.h"

class Application
{
private:
    Window* m_window;
    bool m_running = true;

public:
    Application();

    void run();

    Window* getWindow() { return m_window; }
};


#endif //VOXELGAME_APPLICATION_H
