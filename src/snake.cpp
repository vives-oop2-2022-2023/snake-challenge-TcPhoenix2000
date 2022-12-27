#include "snake.h"

using namespace VIVES;

Snake::Snake(void){
    //create snake of START_LENGTH
    //snake.resize(START_LENGTH);
    for (unsigned int i = 0; i < START_LENGTH; i++){
        snake.push_back({2,2});
    }
    down();
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
}
void Snake::stop(){
    isMoving= false;
}
void Snake::grow(unsigned int delta){
    for (int i=0; i<delta; i++){
        snake.push_back(snake[snake.size()-1]);
    }
}
std::vector<Point>Snake::body(void){
    std::vector<Point> snakeBody;
    for (int i = 1; i < (int) snake.size();i++){
        snakeBody.push_back(snake[i]);
    }
    return snakeBody;
}
Point Snake::head(void){
    return snake.front();
}
        
Point Snake::nextSnakeHeadPosition(){
    Point temp = head();

    switch (direction){
        case Direction::UP:
            temp.y--;
        break;
        case Direction::DOWN:
            temp.y++;
        break;
        case Direction::LEFT:
            temp.x--;
        break;
        case Direction::RIGHT:
            temp.x++;
        break;
    }
    return temp;
}
void Snake::update(){
    
    nextSnakeHeadPosition();
    //for loop generates error 
    for (int i = (int) snake.size(); i > 0;i--)
    {
        //snake.erase(snake.begin()+1);
        snake[i]=snake[i-1];
        //snake.push_back(snake[i]);
    }
    snake.front()= nextSnakeHeadPosition();
}