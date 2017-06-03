#include "Person.h"

Person::Person() : name(""), age(0), gender(Gender::Other)
{
}

Person::Person(std::string name, uint32_t age, Gender gender) :
    name(name), age(age), gender(gender)
{
}
