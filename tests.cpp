#define CATCH_CONFIG_MAIN 
#include "catch.hpp"

#include "Academic.h"
#include "Cleanroom.h"
#include "Research.h"

TEST_CASE("Basic object creation")
{
    SECTION("Person creation")
    {
        Academic p("Alfred", 44, Gender::Male, AcademicTitle::PhD);
        auto info = p.getInfo();
        REQUIRE(info == "Alfred (Academic, 44 y.o.) identifies as male and holds the title of PhD.\n");
    }

    SECTION("Room creation")
    {
        Cleanroom r("001", "M-11", 0.5);
        auto info = r.getInfo();
        REQUIRE(info == "Cleanroom (cleanliness level: 0.5) located in M-11, room number 001.\n");
    }

    SECTION("Work creation")
    {
        Cleanroom r("001", "M-11", 0.5);
        Research w(12, 2, &r, true);
        auto info = w.getInfo();
        REQUIRE(info == "research and writing paper at 12 for 2 hours in Cleanroom (cleanliness level: 0.5) located in M-11, room number 001.\n");
    }
}

TEST_CASE("EnumToString")
{
    SECTION("GenderToString")
    {
        REQUIRE(EnumToString::GenderToString(Gender::Other) == "other");
    }

    SECTION("AcademicTitleToString")
    {
        REQUIRE(EnumToString::AcademicTitleToString(AcademicTitle::Bachelor) == "Bachelor");
    }
}
