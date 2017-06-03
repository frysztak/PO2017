#include <sstream>
#include "Student.h"

Student::Student(std::string name, uint32_t age, Gender gender, 
                uint32_t semester) : 
    Person(name, age, gender), semester(semester)
{
}

std::string Student::getInfo()
{
    std::stringstream ss;
    ss << this->name << " (Student, " << this->age << " y.o.)";
    ss << " identifies as " << EnumToString::GenderToString(this->gender);
    ss << " and currently is on semester number " << semester;
    ss << "." << std::endl;

    return ss.str();
}

void Student::doWork()
{
    // accurate depiction of every student
}
