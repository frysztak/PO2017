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
    ss << "doing didactic work " << attendance << "with ";
    ss << students.size();
    ss << " in " << place->getInfo() << std::endl;

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
