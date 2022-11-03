//#################################
//# Game
//#################################
//# - snake: Snake
//# - canvas: Canvas
//# - isPlaying: bool
//#################################
//# + Game()
//# - update()      update entities
//# - draw()        draw entities on canvas
//# - render()      output canvas to renderer (terminal)
//#################################
#pragma once
#include "snake.h"
#include "canvas.h"

class Game{
    private:
        Snake snake;
        Canvas canvas;
        bool isPlaying;
    public:
        Game();
    private:
        void update();      //update entities
        void draw();        //draw entities on canvas
        void render();      //output canvas to renderer (terminal)
        void StartupSign(); //display startup ascii title sign
};