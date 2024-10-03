#include "logger.h"

namespace seneca {

    void Logger::resize() {
        m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        Event* new_array = new Event[m_capacity];

        for (int i = 0; i < m_count; ++i) {
            new_array[i] = m_event[i];
        }
        delete[] m_event;
        m_event = new_array;
    }

    Logger::~Logger() {
        delete[] m_event;
    }

    Logger::Logger(Logger&& other) noexcept 
        : m_event(other.m_event), m_count(other.m_count), m_capacity(other.m_capacity) {
        other.m_event = nullptr;
        other.m_count = 0;
        other.m_capacity = 0;
    }

    Logger& Logger::operator=(Logger&& other) noexcept {
        if (this != &other) {
            delete[] m_event;
            m_event = other.m_event;
            m_count = other.m_count;
            m_capacity = other.m_capacity;

            other.m_event = nullptr;
            other.m_count = 0;
            other.m_capacity = 0;
        }
        return *this;
    }

    void Logger::addEvent(const Event& event) {
        if (m_count == m_capacity) {
            resize();
        }
        m_event[m_count++] = event;
    }

    std::ostream& operator<<(std::ostream& os, const Logger& logger) {
        for (int i = 0; i < logger.m_count; ++i) {
            os << logger.m_event[i] << std::endl;
        }
        return os;
    }

} // namespace seneca
