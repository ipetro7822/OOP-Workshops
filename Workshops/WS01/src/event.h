#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>
#include "settings.h"

namespace seneca {

    class Event {
        std::string m_name;
        std::chrono::nanoseconds m_duration;

    public:
        Event() = default;
        Event(const char* name, const std::chrono::nanoseconds& duration);

        friend std::ostream& operator<<(std::ostream& os, const Event& event);

    private:
        std::string getFormattedDuration() const;
        static int getDurationFieldSize();
    };

} // namespace seneca

#endif // SENECA_EVENT_H
