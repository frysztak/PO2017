#ifndef _RESEARCH_H_
#define _RESEARCH_H_

#include "Work.h"

class Research : public Work
{
    protected:
        bool writePaper;

    public:
        Research(uint32_t startTime, uint32_t duration, Room* place,
                bool writePaper);
        std::string getInfo();
};

#endif
