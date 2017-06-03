#include <sstream>
#include "Research.h"

Research::Research(uint32_t startTime, uint32_t duration, Room* place,
                   bool writePaper) :
    Work(startTime, duration, place), writePaper(writePaper)
{
}

std::string Research::getInfo()
{
    std::stringstream ss;
    std::string paper = writePaper ? " and writing paper" : "";
    ss << "doing research" << paper << "in " << place->getInfo();
    ss << std::endl;

    return ss.str();
}
