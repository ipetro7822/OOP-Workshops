#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include "event.h"
#include <chrono>

namespace seneca {
    class TimeMonitor {
        const char* m_event_name;
        std::chrono::high_resolution_clock::time_point m_start_time;

    public:
        void startEvent(const char* name);
        Event stopEvent();
    };

} // namespace seneca

#endif // SENECA_TIMEMONITOR_H
