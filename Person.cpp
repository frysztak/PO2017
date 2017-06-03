#include "Person.h"

std::string EnumToString::GenderToString(Gender g)
{
    switch(g)
    {
        case Gender::Male:
            return "male";
        case Gender::Female:
            return "female";
        default:
            return "other";
    }
}

std::string EnumToString::AcademicTitleToString(AcademicTitle t)
{
    switch(t)
    {
        case AcademicTitle::Bachelor:
            return "Bachelor";
        case AcademicTitle::Master:
            return "Master";
        case AcademicTitle::PhD:
            return "PhD";
        case AcademicTitle::Professor:
            return "Professor";
        default:
            return "Unknown";
    }
}

Person::Person() : name(""), age(0), gender(Gender::Other)
{
}

Person::Person(std::string name, uint32_t age, Gender gender) :
    name(name), age(age), gender(gender)
{
}
