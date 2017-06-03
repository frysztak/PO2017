#include <sstream>
#include "Cleanroom.h"

Cleanroom::Cleanroom(std::string number, std::string building, 
                     float cleanliness) :
    Room(number, building), cleanliness(cleanliness)
{
}

std::string Cleanroom::getInfo()
{
    std::stringstream ss;
    ss << "Cleanroom (cleanliness level: " << cleanliness;
    ss << ") located in " << building << ", room number " << number; 
    ss << "." << std::endl;

    return ss.str();
}
