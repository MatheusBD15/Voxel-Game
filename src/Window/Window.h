//
// Created by MatheusBD on 27/11/2021.
//

#ifndef VOXELGAME_WINDOW_H
#define VOXELGAME_WINDOW_H

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>
#include <Camera/Camera.h>
#include <functional>
#include "Events/Event.h"

class Window
{
private:
    using EventCallbackFn = std::function<void(Event&)>;

    struct WindowData
    {
        EventCallbackFn eventCallback;
        int width, height;
    };

    WindowData m_Data;
    GLFWwindow* m_Window;

public:

    Window();

    void start();

    void close();

    void update(float deltaTime);

    void postUpdate();

    inline GLFWwindow* getWindow() { return m_Window; };

    void processInput(float deltaTime);

    inline void setEventCallback(const EventCallbackFn& callback) { m_Data.eventCallback = callback; }

    void setGLFWCallbacks();

    void mouseCallback(GLFWwindow* window, double xpos, double ypos);
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void mouseCallback(GLFWwindow* window, double xpos, double ypos);



#endif //VOXELGAME_WINDOW_H
