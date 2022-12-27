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
//# + start()       start
//# + stop()        stop
//#################################
#pragma once
#include "snake.h"
#include "canvas.h"
#include "renderers/bitmap_renderer.h"
#include "renderers/TextRenderer.h"

namespace VIVES{
    class Game{
        private:
            Snake snake;
            Canvas canvas;
            //BitmapRenderer bitmap;
            TextRenderer text_renderer;

            bool _isPlaying = true;
        public:
            Game(void);
            void start(void);
            void StartupSign(void); //display startup ascii title sign
        private:
            void update(void);      //update entities
            void draw(void);        //draw entities on canvas
            void render(void);      //output canvas to renderer (terminal)
            void collisionDetect(void); // 
    };
}