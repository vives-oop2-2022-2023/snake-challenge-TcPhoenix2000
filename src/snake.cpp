#include "snake.h"

using namespace VIVES;

Snake::Snake(void){
    
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
    
}
