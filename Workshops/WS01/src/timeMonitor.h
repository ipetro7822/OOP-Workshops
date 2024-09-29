#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H
#include <chrono>

namespace seneca{
    class TimeMonitor{
        
        public:
            void startEvent(const char* name);
            Event stopEvent();
            
    };
}
#endif //SENECA_TIMEMONITOR_H