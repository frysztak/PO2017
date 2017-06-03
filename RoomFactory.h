#ifndef _ROOMFACTORY_H_
#define _ROOMFACTORY_H_

#include <vector>
#include <memory>
#include "LectureHall.h"
#include "Cleanroom.h"
#include "Classroom.h"

class AbstractRoomFactory
{
    public:
        virtual Room* createRoom() = 0;

    protected:
        const static std::vector<std::string> knownBuildings;

        bool randomBool();
        std::string randomBuilding();
        std::string randomNumber();
};

class LectureHallFactory : public AbstractRoomFactory
{
    public:
        Room* createRoom();
};

class ClassroomFactory : public AbstractRoomFactory
{
    public:
        Room* createRoom();
};

class CleanroomFactory : public AbstractRoomFactory
{
    public:
        Room* createRoom();
    protected:
        float randomCleanliness();
};

class RoomFactory
{
    public:
        static 
        std::unique_ptr<AbstractRoomFactory> getFactory(std::string);
};

#endif
