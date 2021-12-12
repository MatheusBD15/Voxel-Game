//
// Created by MBDambo on 11/12/2021.
//

#ifndef VOXELGAME_KEYEVENT_H
#define VOXELGAME_KEYEVENT_H

#include "Event.h"

class KeyEvent : public Event
{
protected:
    int m_KeyCode;

    KeyEvent(int keycode)
        : m_KeyCode(keycode) {}

public:
    inline int GetKeyCode() const { return m_KeyCode; }

    EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
};

class KeyPressedEvent : public KeyEvent
{
private:
    int m_RepeatCount;

public:
    KeyPressedEvent(int keycode, int repeatCount)
        : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

    inline int GetRepeatCount() const { return m_RepeatCount; }

    EVENT_CLASS_TYPE(KeyPressed)
};

class KeyReleasedEvent : public KeyEvent
{
public:
    KeyReleasedEvent(int keycode)
        : KeyEvent(keycode) {}

    EVENT_CLASS_TYPE(KeyPressed)
};

#endif //VOXELGAME_KEYEVENT_H
