#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include "event.h"
namespace seneca
{
    class Logger
    {
        Event *event;

        public:
            Logger();
            ~Logger();
            Logger& operator=(Logger&& other);
            void addEvent(const Event& event);
            friend std::ostream& operator<<(std::ostream, const Logger& l);
    };
}
#endif // SENECA_LOGGER_H