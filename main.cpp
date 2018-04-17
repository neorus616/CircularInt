#include <iostream>

#include "CircularInt.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cassert>

using namespace std;

    CircularInt hour {1, 12};

TEST_CASE("testing the assignment operators") {
    CHECK(hour == 1);
    hour = hour - 4;
    CHECK(hour == 9);
    hour = hour + 12; // should have no effect
    CHECK(hour == 9);
}

TEST_CASE("testing the addition operators") {
    hour += 4;
    CHECK(hour == 1);
    hour = hour + 33;
    CHECK(hour == 10);
    hour++;
    CHECK(hour == 11);
    hour++;
    CHECK(hour == 12);
    hour++;
    CHECK(hour == 1);
    CircularInt tmpHour {1, 12};
    tmpHour = 16 + tmpHour;
    CHECK(tmpHour == 5);
    hour += tmpHour;
    CHECK(hour == 6);
    hour = tmpHour + 7;
    CHECK(hour == 12);
    hour = tmpHour + hour;
    CHECK(hour == 5);
    tmpHour++;
    hour = tmpHour++;
    CHECK(hour == 6);
    CHECK(tmpHour == 7);
    hour = ++tmpHour;
    CHECK(hour == 8);
    CHECK(tmpHour == 8);
}

TEST_CASE("testing the addition functions"){
	CHECK(hour == 8);
	hour /= 11;
	CHECK_THROWS_AS(hour/=11, std::exception);
}