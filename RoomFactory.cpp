#include <random>
#include "RoomFactory.h"

const std::vector<std::string> AbstractRoomFactory::knownBuildings = 
{ "C2", "M11", "M6-bis" };

std::string AbstractRoomFactory::randomBuilding()
{
    size_t size = knownBuildings.size();

    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(0, size-1);

    return knownBuildings[dist(engine)];
}

std::string AbstractRoomFactory::randomNumber()
{
}

bool AbstractRoomFactory::randomBool()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist;
    return dist(engine) % 2;
}

Room* LectureHallFactory::createRoom()
{
    return new LectureHall(randomNumber(), randomBuilding(), 
                           randomBool()); 
}

Room* ClassroomFactory::createRoom()
{
    return new Classroom(randomNumber(), randomBuilding(), 
                         randomBool()); 
}

float CleanroomFactory::randomCleanliness()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_real_distribution<float> dist(0.1, 0.95);
    return dist(engine);
}

Room* CleanroomFactory::createRoom()
{
    return new Cleanroom(randomNumber(), randomBuilding(), 
                         randomCleanliness()); 
}

std::unique_ptr<AbstractRoomFactory> 
RoomFactory::getFactory(std::string type)
{
    if (type == "LectureHall")
        return std::make_unique<LectureHallFactory>();
    else if (type == "Classroom") 
        return std::make_unique<ClassroomFactory>();
    else if (type == "Cleanroom")
        return std::make_unique<CleanroomFactory>();
    else
        return nullptr;
}
