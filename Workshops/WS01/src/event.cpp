#include "event.h"

namespace seneca {

    Event::Event(const char* name, const std::chrono::nanoseconds& duration)
        : m_name(name), m_duration(duration) {}

    std::ostream& operator<<(std::ostream& os, const Event& event) {
        static int counter = 0;
        ++counter;

        os << std::setw(2) << counter << ": " 
           << std::setw(40) << event.m_name << " -> "
           << std::setw(event.getDurationFieldSize()) << event.getFormattedDuration() 
           << " " << seneca::g_settings.m_time_units;

        return os;
    }

    std::string Event::getFormattedDuration() const {
        if (seneca::g_settings.m_time_units == "seconds")
            return std::to_string(std::chrono::duration_cast<std::chrono::seconds>(m_duration).count());
        else if (seneca::g_settings.m_time_units == "milliseconds")
            return std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(m_duration).count());
        else if (seneca::g_settings.m_time_units == "microseconds")
            return std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(m_duration).count());
        else
            return std::to_string(m_duration.count());
    }

    int Event::getDurationFieldSize() {
        if (seneca::g_settings.m_time_units == "seconds") return 2;
        if (seneca::g_settings.m_time_units == "milliseconds") return 5;
        if (seneca::g_settings.m_time_units == "microseconds") return 8;
        return 11;
    }

} // namespace seneca
