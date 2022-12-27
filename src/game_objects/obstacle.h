// #################################
// # Obstacle
// #################################
// # - point: Point
// #################################
// # + obstacle(point: Point)
// #################################
#pragma once
#include "gameObject.h"

namespace VIVES{
    class Obstacle :public GameObject{
        private:
            Point _point;
        public:
            Obstacle(Point point); 
    };
    inline Obstacle::Obstacle(Point point):GameObject(point){}
}