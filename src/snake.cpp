#include "snake.h"

using namespace VIVES;

Snake::Snake(void){
    if (isMoving==true){
        update();
    }
}
void Snake::up(){
    direction= Direction::UP;
}
void Snake::down(){
    direction= Direction::DOWN;
}
void Snake::left(){
    direction= Direction::LEFT;
}
void Snake::right(){
    direction= Direction::RIGHT;
}
void Snake::start(){
    isMoving= true;
    update();
}
void Snake::stop(){
    isMoving= false;
}
void Snake::grow(unsigned int delta){
    
}
std::vector<Point>Snake::body(void){
    
    return  body();//tmp
}
Point Snake::head(void){
    return head();//tmp
}
void Snake::update(){
    switch (direction){
    {
        case Direction::UP:
            //head.y --;
            /* code */
            break;
        case Direction::DOWN:
            //head.y ++;
            /* code */
            break;
        case Direction::LEFT:
            //head.x --;
            /* code */
            break;
        case Direction::RIGHT:
            //head.x ++;
            /* code */
            break;
        }
    }
    
}
