#include <sstream>
#include "Study.h"

Study::Study(uint32_t startTime, uint32_t duration, Room* place,
             bool eatCheetos) :
    Work(startTime, duration, place), eatCheetos(eatCheetos)
{
}

std::string Study::getInfo()
{
    std::stringstream ss;
    std::string cheetos = eatCheetos ? "and eating Cheetos " : "";
    ss << "studying " << cheetos << "in " << place->getInfo();
    ss << std::endl;

    return ss.str();
}
