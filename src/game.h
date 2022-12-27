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
#include <vector>

#include "./game_objects/gameObject.h"
#include "./game_objects/obstacle.h"
#include "./game_objects/edible.h"
#include "./game_objects/collisionDetector.h"

#include "./renderers/render_interface.h"
#include "./renderers/TextRenderer.h"

namespace VIVES{
    class Game{
        private:
            Snake snake;
            Canvas canvas;
            IRender * _render = new TextRenderer();

            std::vector<Obstacle> _walls;
            std::vector<Edible> edibles;


            bool _isPlaying = true;
        public:
            Game(void);
            void start(void);
            void stop(void);
            void StartupSign(void); //display startup ascii title sign
            void setRenderer(IRender * render);
        private:
            void keyCheck(void);
            void walls(void);
            void update(void);      //update entities
            void draw(void);        //draw entities on canvas
            void renderer(void);      //output canvas to renderer (terminal)
            void createEdible();
    };
}