//
// Created by MBDambo on 11/12/2021.
//

#ifndef VOXELGAME_MOUSEEVENT_H
#define VOXELGAME_MOUSEEVENT_H

#include "Event.h"

class MouseMovedEvent : public Event
{
private:
    float m_MouseX, m_MouseY;

public:
    MouseMovedEvent(float x, float y)
        : m_MouseX(x), m_MouseY(y) {}

    inline float GetX() const { return m_MouseX; }
    inline float GetY() const { return m_MouseY; }

    // Only for debugging purposes
    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseX;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseMoved)
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
};

class MouseScrolledEvent : public Event
{
private:
    float m_XOffset, m_YOffset;

public:
    MouseScrolledEvent(float xOffset, float yOffset)
        : m_XOffset(xOffset), m_YOffset(yOffset) {}

    inline float GetXOffset() const { return m_XOffset; }
    inline float GetYOffset() const { return m_YOffset; }

    // Only for debugging purposes
    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseScrolled)
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
};

class MouseButtonEvent : public Event
{
public:
    inline int GetMouseButton() const { return m_Button; }

    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

protected:
    MouseButtonEvent(int button)
        : m_Button(button) {}

    int m_Button;
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
    MouseButtonPressedEvent(int button)
        : MouseButtonEvent(button) {}

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseButtonPressedEvent: " << m_Button;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonPressed)
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
    MouseButtonReleasedEvent(int button)
        : MouseButtonEvent(button) {}

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseButtonReleasedEvent: " << m_Button;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonReleased)
};

#endif //VOXELGAME_MOUSEEVENT_H
