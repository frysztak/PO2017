#ifndef _DIDACTICWORK_H_
#define _DIDACTICWORK_H_

#include <vector>
#include "Student.h"
#include "Work.h"

class DidacticWork : public Work
{
    protected:
        bool checkAttendance;
        std::vector<Student*> students;

    public:
        DidacticWork(uint32_t startTime, uint32_t duration, Room* place,
                   bool checkAttendance);
        std::string getInfo();
        void setStudents(std::vector<Student*>&);
};

#endif
