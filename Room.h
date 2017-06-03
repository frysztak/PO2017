#ifndef _ROOM_H_
#define _ROOM_H_

#include <string>

class Room
{
    private:
        std::string number;
        std::string building;

    public:
        Room();
        Room(std::string number, std::string building);

        virtual std::string getInfo() = 0;
};

#endif
