#include "timeMonitor.h"
#include <chrono>

namespace seneca {

    void TimeMonitor::startEvent(const char* name) {
        m_event_name = name;
        m_start_time = std::chrono::high_resolution_clock::now();
    }

    Event TimeMonitor::stopEvent() {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - m_start_time);
        return Event(m_event_name, duration);
    }

} // namespace seneca
