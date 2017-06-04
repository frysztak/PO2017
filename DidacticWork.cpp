#include <sstream>
#include "DidacticWork.h"

DidacticWork::DidacticWork(uint32_t startTime, uint32_t duration, 
                           Room* place, bool checkAttendance) :
    Work(startTime, duration, place), checkAttendance(checkAttendance)
{
}

std::string DidacticWork::getInfo()
{
    std::stringstream ss;
    std::string attendance = checkAttendance ? 
        "and checking attendance " : "";
    ss << "didactic work " << attendance;
    ss << "at " << startTime << " for " << duration << " hours";
    ss << " with " << students.size() << " students";
    ss << " in " << place->getInfo();

    return ss.str();
}

void DidacticWork::setStudents(std::vector<Student*>& students)
{
    this->students.clear();
    this->students = students;
}

const std::vector<Student*>& DidacticWork::getStudents()
{
    return students;
}
