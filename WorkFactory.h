#ifndef _WORKFACTORY_H_
#define _WORKFACTORY_H_

#include <vector>
#include <memory>
#include "Research.h"
#include "DidacticWork.h"
#include "Study.h"

class AbstractWorkFactory
{
    public:
        virtual Work* createWork(Room* place) = 0;

    protected:
        bool randomBool();
        uint32_t randomStartTime();
        uint32_t randomDuration();
};

class ResearchWorkFactory : public AbstractWorkFactory
{
    public:
        Work* createWork(Room* place);
};

class DidacticWorkFactory : public AbstractWorkFactory
{
    public:
        Work* createWork(Room* place);
};

class StudyWorkFactory : public AbstractWorkFactory
{
    public:
        Work* createWork(Room* place);
};

class WorkFactory
{
    public:
        static 
        std::unique_ptr<AbstractWorkFactory> getFactory(std::string);
};

#endif
