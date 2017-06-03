#include <random>
#include "PeopleFactory.h"

const std::vector<std::string> AbstractPeopleFactory::maleNames = 
{ "Tom", "Krysztof", "Jan" };
const std::vector<std::string> AbstractPeopleFactory::femaleNames = 
{ "Joanna", "Helga", "Wiolonczela" };

Gender AbstractPeopleFactory::randomGender()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(1, 3);

    auto result = dist(engine);
    if (result == 1)
        return Gender::Male;
    else if (result == 2)
        return Gender::Female;
    else
        return Gender::Other;
}

std::string AbstractPeopleFactory::randomName(Gender g)
{
    size_t size;
    if (g == Gender::Male)
        size = this->maleNames.size();
    else if (g == Gender::Female)
        size = this->femaleNames.size();
    else
        size = this->femaleNames.size() + this->maleNames.size();

    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(0, size-1);

    auto idx = dist(engine);
    if (g == Gender::Male)
        return this->maleNames[idx];
    else if (g == Gender::Female)
        return this->femaleNames[idx];
    else
    {
        std::vector<std::string> commonVec(this->maleNames.begin(),
                                           this->maleNames.end());
        commonVec.insert(commonVec.end(), this->femaleNames.begin(),
                                          this->femaleNames.end());
        return commonVec[idx];
    }
}

uint32_t AbstractPeopleFactory::randomAge()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(20, 99);
    return dist(engine);
}

AcademicTitle AcademicFactory::randomAcademicTitle()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(1, 4);

    switch(dist(engine))
    {
        case 1:
            return AcademicTitle::Bachelor;
        case 2:
            return AcademicTitle::Master;
        case 3:
            return AcademicTitle::PhD;
        case 4:
            return AcademicTitle::Professor;
        default:
            return AcademicTitle::Bachelor;
    }
}

Person* AcademicFactory::createPerson()
{
    auto g = this->randomGender();
    return new Academic(randomName(g), randomAge(), g, 
                        randomAcademicTitle());
}

uint32_t StudentFactory::randomSemester()
{
    std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(1, 7);
    return dist(engine);
}

Person* StudentFactory::createPerson()
{
    auto g = this->randomGender();
    return new Student(randomName(g), randomAge(), g, randomSemester());
}


std::unique_ptr<AbstractPeopleFactory> 
PeopleFactory::getFactory(std::string type)
{
    if (type == "Academic")
        return std::make_unique<AcademicFactory>();
    else if (type == "Student") 
        return std::make_unique<StudentFactory>();
    else
        return nullptr;
}
