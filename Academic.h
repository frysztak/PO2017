#ifndef _ACADEMIC_H_
#define _ACADEMIC_H_

#include "Person.h"

class Academic : public Person
{
    private:
        AcademicTitle title;

    public:
        Academic(std::string name, uint32_t age, Gender gender, 
                AcademicTitle title);

        std::string getInfo();
        void doWork();
};

#endif
