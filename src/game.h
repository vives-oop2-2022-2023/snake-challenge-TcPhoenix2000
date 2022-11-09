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
#include "helpers/bitmap_generator.h"
#include "renderers/TextRenderer.h"

namespace VIVES{
    class Game{
        private:
            Snake _snake;
            Canvas _canvas;
            BitmapGenerator bitmap;
            TextRenderer text_renderer;

            bool _isPlaying;
        public:
            Game(void);
            void start(void);
        private:
            void update(void);      //update entities
            void draw(void);        //draw entities on canvas
            void render(void);      //output canvas to renderer (terminal)

            void StartupSign(void); //display startup ascii title sign
    };
}