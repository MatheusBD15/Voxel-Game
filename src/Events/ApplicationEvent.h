//
// Created by MBDambo on 11/12/2021.
//

#ifndef VOXELGAME_APPLICATIONEVENT_H
#define VOXELGAME_APPLICATIONEVENT_H

#include "Event.h"

class WindowResizeEvent : public Event
{
private:
    unsigned int m_Width, m_Height;

public:
    WindowResizeEvent(unsigned int width, unsigned int height)
        : m_Width(width), m_Height(height) {}

    inline unsigned int GetWidth() const { return m_Width; }
    inline unsigned int GetHeight() const { return m_Height; }

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
        return ss.str();
    }

    EVENT_CLASS_TYPE(WindowResize)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class WindowCloseEvent : public Event
{
public:
    WindowCloseEvent() = default;

    EVENT_CLASS_TYPE(WindowClose)
    EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

#endif //VOXELGAME_APPLICATIONEVENT_H
