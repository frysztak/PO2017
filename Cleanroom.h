#ifndef _CLEANROOM_H_
#define _CLEANROOM_H_

#include "Room.h"

class Cleanroom : public Room
{
    private:
        float cleanliness;

    public:
        Cleanroom(std::string number, std::string building,
                  float cleanliness);
        std::string getInfo();
};

#endif
