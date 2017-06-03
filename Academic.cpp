#include <sstream>
#include "Academic.h"

Academic::Academic(std::string name, uint32_t age, Gender gender, 
                    AcademicTitle title) : 
    Person(name, age, gender), title(title)
{
}

std::string Academic::getInfo()
{
    std::stringstream ss;
    ss << this->name << " (Academic, " << this->age << " y.o.)";
    ss << " identifies as " << EnumToString::GenderToString(this->gender);
    ss << " and holds the title of ";
    ss << EnumToString::AcademicTitleToString(this->title);
    ss << "." << std::endl;

    return ss.str();
}

void Academic::doWork()
{
}
