#include "snake.h"

using namespace VIVES;

Snake::Snake(void){
    //create snake of START_LENGTH
    snake.resize(START_LENGTH);
    snake.push_back({2,2});
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
/*
        dit zou is aant begin van de functie een point opslaan van head()
        dan aan gelang  de direction doe ik x of y +1
        dan doe ik voor elk bodyelement zet ik gelijk aan het bodyelement voor hem 
        en daarna zet ik head geklijk aan het punt dat in het begin opgelsagen is*/
        
void Snake::update(){
    //
    switch (direction){
    {
        case Direction::UP:
            //head().y --;
            
            break;
        case Direction::DOWN:
            Point temp = head();
            head().y+1;

            for (int i = 0; i < (int) snake.size();i++){
                snake[i]=snake[i-1];
                snake.push_back(snake[i]);
            }
            head() = temp;
            
            //snake.push_back({head().x,y});
            //snake.insert(snake.begin(),{y,head().x});
            
            break;
        /*case Direction::LEFT:
            //head().x --;
           
            break;
        case Direction::RIGHT:
            //head().x ++;
            
            break;
        */}
    }
}