#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "Person.h"

class Student : public Person
{
    private:
        uint32_t semester; // is 32-bit int large enough?

    public:
        Student(std::string name, uint32_t age, Gender gender, 
                uint32_t semester);

        std::string getInfo();
        void doWork();
};

#endif
