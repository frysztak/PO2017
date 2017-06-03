#ifndef _LECTUREHALL_H_
#define _LECTUREHALL_H_

#include "Room.h"

class LectureHall : public Room
{
    private:
        bool hasAC;

    public:
        LectureHall(std::string number, std::string building, bool hasAC);
        std::string getInfo();
};

#endif
