#ifndef _WORK_H_
#define _WORK_H_

#include "Room.h"

class Work
{
    private:
        uint32_t startTime;
        uint32_t duration;
        Room* place;

    public:
        Work();
        Work(uint32_t startTime, uint32_t duration, Room* place);
};

#endif
