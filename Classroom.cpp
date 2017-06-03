#include <sstream>
#include "Classroom.h"

Classroom::Classroom(std::string number, std::string building, 
                     bool areSeatsComfortable) :
    Room(number, building), areSeatsComfortable(areSeatsComfortable)
{
}

std::string Classroom::getInfo()
{
    std::stringstream ss;
    std::string seats = areSeatsComfortable ? "w/ comfy seats" : 
                                              "w/o comfy seats";
    ss << "Classroom (" << seats << ") located";
    ss << " in " << building << ", room number " << number << ".";
    ss << std::endl;

    return ss.str();
}
