#include <random>
#include "WorkFactory.h"

bool AbstractWorkFactory::randomBool()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist;
    return dist(engine) % 2;
}

uint32_t AbstractWorkFactory::randomStartTime()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(7, 16);
    return dist(engine);
}

uint32_t AbstractWorkFactory::randomDuration()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(1, 3);
    return dist(engine);
}

Work* ResearchWorkFactory::createWork(Room* place)
{
    return new Research(randomStartTime(), randomDuration(),
                        place, randomBool());
}

Work* DidacticWorkFactory::createWork(Room* place)
{
    return new DidacticWork(randomStartTime(), randomDuration(),
                           place, randomBool());
}

Work* StudyWorkFactory::createWork(Room* place)
{
    return new Study(randomStartTime(), randomDuration(),
                     place, randomBool());
}

std::unique_ptr<AbstractWorkFactory> 
WorkFactory::getFactory(std::string type)
{
    if (type == "Research")
        return std::make_unique<ResearchWorkFactory>();
    else if (type == "Didactic") 
        return std::make_unique<DidacticWorkFactory>();
    else if (type == "Study")
        return std::make_unique<StudyWorkFactory>();
    else
        return nullptr;
}
