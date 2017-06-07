#include <iostream>
#include <algorithm>
#include <random>
#include "PeopleFactory.h"
#include "RoomFactory.h"
#include "WorkFactory.h"

int main(int argc, char** argv)
{
    auto academic = PeopleFactory::getFactory("Academic")->createPerson();

    std::vector<Student*> students(12);
    std::generate(std::begin(students), std::end(students),
    []() { return (Student*)PeopleFactory::getFactory("Student")->
                  createPerson(); });

    std::vector<Room*> rooms(6);
    std::generate(std::begin(rooms), std::begin(rooms) + 3,
    []() { return RoomFactory::getFactory("LectureHall")->
                  createRoom(); });
    std::generate(std::begin(rooms) + 2, std::begin(rooms) + 5,
    []() { return RoomFactory::getFactory("Classroom")->
                  createRoom(); });
    std::generate(std::begin(rooms) + 4, std::end(rooms),
    []() { return RoomFactory::getFactory("Cleanroom")->
                  createRoom(); });

    auto randomCleanroom = [&rooms]()
    {
        std::random_device random_device;
	    std::mt19937 engine{random_device()};
	    std::uniform_int_distribution<int> dist(4, rooms.size()-1);
        return rooms[dist(engine)];
    };
        
    auto randomRoom = [&rooms]()
    {
        std::random_device random_device;
	    std::mt19937 engine{random_device()};
	    std::uniform_int_distribution<int> dist(0, rooms.size()-1);
        return rooms[dist(engine)];
    };

    std::cout << academic->getInfo() << " and does following work: ";


    for(int i = 1; i < 6; i++)
    {
        std::cout << std::endl << "*** Day " << i << std::endl;

        // create some work
        std::vector<Work*> work(4);
        std::generate(std::begin(work), std::begin(work) + 3,
        [&]() { return WorkFactory::getFactory("Research")->
                      createWork(randomCleanroom()); });
        std::generate(std::begin(work) + 2, std::end(work),
        [&]() { return WorkFactory::getFactory("Didactic")->
                      createWork(randomRoom()); });

        // add some students to didactic work
        std::for_each(std::begin(work) + 2, std::end(work),
        [&students](Work* w)
        {
            std::random_shuffle(std::begin(students),
                                std::end(students)); 

            std::random_device random_device;
	        std::mt19937 engine{random_device()};
	        std::uniform_int_distribution<int> dist(0, students.size()-1);
            auto count = dist(engine);

            DidacticWork* d_w = (DidacticWork*)w;
            auto tmp = std::vector<Student*>(std::begin(students),
                       std::begin(students) + count);
            d_w->setStudents(tmp);
        });

        // sort the work
        std::sort(work.begin(), work.end(),
        [](Work *w1, Work *w2) 
        { 
            return w1->getStartTime() < w2->getStartTime(); 
        });

        // now, finally, do it
        academic->addWork(work);
        while(academic->hasMoreWork())
        {
            auto futureWork = academic->nextWorkItem();
            std::cout << "trying to perform work: ";
            std::cout << futureWork->getInfo();

            auto didactic = dynamic_cast<DidacticWork*>(futureWork);
            if(didactic != nullptr)
            {
                std::cout << "with following students: " << std::endl;
                for(auto s: didactic->getStudents())
                    std::cout << "   " << s->getInfo();
            }

            try {
                academic->doWork();
                std::cout << "work done.";
            }
            catch(const std::logic_error& e)
            {
                std::cout << std::endl << "exception caught: ";
                std::cout << e.what() << std::endl;
                std::cout << "removing this work item and moving on";
                std::cout << std::endl;
                academic->removeWork(1);
            }

            std::cout << std::endl;
        }

        for(auto& w: work)
            delete w;
    }

    for(auto& s: students)
        delete s;
    for(auto& r: rooms)
        delete r;

    return 0;
}
