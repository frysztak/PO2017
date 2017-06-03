#ifndef _CLASSROOM_H_
#define _CLASSROOM_H_

#include "Room.h"

class Classroom : public Room
{
    private:
        bool areSeatsComfortable;

    public:
        Classroom(std::string number, std::string building,
                  bool areSeatsComfortable);
        std::string getInfo();
};

#endif
