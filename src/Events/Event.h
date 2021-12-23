//
// Created by MBDambo on 11/12/2021.
//

#ifndef VOXELGAME_EVENT_H
#define VOXELGAME_EVENT_H

#include <sstream>
#include <functional>
#include <string>

#define BIT(x) (1 << x)

enum class EventType
{
    None = 0,
    WindowClose, WindowResize,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased,
    MouseMoved, MouseScrolled
};

enum EventCategory
{
    None = 0,
    EventCategoryApplication    = BIT(0),
    EventCategoryInput          = BIT(1),
    EventCategoryKeyboard       = BIT(2),
    EventCategoryMouse          = BIT(3),
    EventCategoryMouseButton    = BIT(4)
};

#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::type; }\
                                virtual EventType getEventType() const override { return getStaticType(); }\
                                virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

class Event
{
    friend class EventDispatcher;
public:
    virtual EventType getEventType() const = 0;
    virtual const char* getName() const = 0;
    virtual int getCategoryFlags() const = 0;
    virtual std::string toString() const { return getName(); }

    inline bool isInCategory(EventCategory category)
    {
        return getCategoryFlags() & category;
    }
    bool handled = false;
};

class EventDispatcher
{
private:
    Event& m_Event;
    template<typename T>
    using EventFn = std::function<bool(T&)>;
public:
    EventDispatcher(Event& event)
        : m_Event(event)
    {}

    template<typename T>
    bool dispatch(EventFn<T> func)
    {
        if(m_Event.getEventType() == T::getStaticType())
        {
            m_Event.handled = func(*(T*)&m_Event);
            return true;
        }
        return false;
    }
};

#endif //VOXELGAME_EVENT_H
