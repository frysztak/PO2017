#include <sstream>
#include "LectureHall.h"

LectureHall::LectureHall(std::string number, std::string building, 
                         bool hasAC) :
    Room(number, building), hasAC(hasAC)
{
}

std::string LectureHall::getInfo()
{
    std::stringstream ss;
    std::string ac = hasAC ? "w/ AC" : "w/o AC";
    ss << "Lecture hall (" << ac << ") located";
    ss << " in " << building << ", room number " << number << ".";
    ss << std::endl;

    return ss.str();
}
