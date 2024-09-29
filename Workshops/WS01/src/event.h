#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <iostream>
#include "timeMonitor.h"
namespace seneca
{
    class Event
    {
        std::string m_event_name;
        std::chrono::nanoseconds nano;

    public:
        Event();
        Event(const char* name, const std::chrono::nanoseconds& duration)l
        friend std::ostream& operator<<(std::ostream, const Event& e);
    };
}
#endif // SENECA_EVENT_H