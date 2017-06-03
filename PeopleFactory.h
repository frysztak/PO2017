#ifndef _PEOPLEFACTORY_H_
#define _PEOPLEFACTORY_H_

#include <vector>
#include "Academic.h"
#include "Student.h"

class AbstractPeopleFactory
{
    public:
        virtual Person* createPerson() = 0;

    protected:
        const static std::vector<std::string> femaleNames;
        const static std::vector<std::string> maleNames;

        Gender randomGender();
        uint32_t randomAge();
        std::string randomName(Gender);
};

class AcademicFactory : public AbstractPeopleFactory
{
    public:
        Person* createPerson();
    private:
        AcademicTitle randomAcademicTitle();
};

class StudentFactory : public AbstractPeopleFactory
{
    public:
        Person* createPerson();
    private:
        uint32_t randomSemester();
};

class PeopleFactory
{
    public:
        static 
        std::unique_ptr<AbstractPeopleFactory> getFactory(std::string);
};

#endif
