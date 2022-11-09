//#################################
//# Snake
//#################################
//# - snake: std::vector<Point>
//# - direction: Direction
//# - isMoving: bool
//# - START_LENGTH: unsigned int = 3
//#################################
//# + Snake()       create snake of START_LENGTH
//# + up()
//# + down()
//# + left()
//# + right()
//# + stop()
//# + grow(delta: unsigned int)
//# + body(): std::vector<Point>
//# + head(): Point
//# + update()
//#################################
#pragma once
#include "point.h"
#include "direction.h"
#include <vector>
namespace VIVES{
    class Snake
    {
        private:
            std::vector<Point> snake;
            Direction direction;
            bool isMoving;
            unsigned int START_LENGTH = 3;
        public:
            Snake(void);       //create snake of START_LENGTH
            void up();
            void down();
            void left();
            void right();
            void start();
            void stop();
            void grow(unsigned int delta);
            std::vector<Point>body();
            Point head();
            void update();
    };
}