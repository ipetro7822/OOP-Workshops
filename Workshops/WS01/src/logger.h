#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include "event.h"

namespace seneca {

    class Logger {
        Event *m_event = nullptr;
        int m_count = 0;
        int m_capacity = 0;

        void resize();

    public:
        Logger() = default;
        ~Logger();
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        Logger(Logger&& other) noexcept;
        Logger& operator=(Logger&& other) noexcept;

        void addEvent(const Event& event);
        friend std::ostream& operator<<(std::ostream& os, const Logger& logger);
    };
} // namespace seneca

#endif // SENECA_LOGGER_H
