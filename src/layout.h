//#################################
//# Layout (may need a better name)
//#################################
//# - width: unsigned int
//# - height: unsigned int
//# - walls: std::vector<Point>
//#################################
//# + Layout(width: unsigned int, height: unsigned int)       setup perimeter
//# + update()                                                probable does nothing
//# + blocks(): std::vector<Point>
//#################################
#pragma once
#include <point.h>
#include <vector>

class layout
{
    private:
        unsigned int width,height;
        std::vector<Point> walls;
    public:
        void Layout(unsigned int width,unsigned int height);        //setup perimeter
        void update();                                              //probable does nothing
        std::vector<Point>blocks(); 
};