// #################################
// # Obstacle
// #################################
// # - point: Point
// #################################
// # + obstacle(point: Point)
// #################################
#pragma once
#include "point.h"
namespace VIVES{
    class Obstacle
    {
        private:
            Point point;
        public:
            Obstacle(Point point); 
    };
}