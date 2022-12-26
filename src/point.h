//#################################
//# Point <<struct>>
//#################################
//# + x: size_t
//# + y: size_t
//#################################
#pragma once
#include <cstddef>

struct Point
{
    size_t x = 0 , y =0;
    //?? fixet walls.cpp
    Point(size_t x, size_t y) : x(x), y(y) {}
};