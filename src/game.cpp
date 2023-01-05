#include "game.h"
#include "./lib/terminal.h"
#include "./lib/gameMenu.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace VIVES;

const int ROWS=40;//horizontal
const int COLS=15;//vertical
    Game::Game(void):canvas(ROWS,COLS){
    }
    void Game::start(){
        Bios::Terminal::flush();
        Bios::Terminal::clear();
        _isPlaying=true;

        walls();
        createEdible();
        snake.start();
        while (_isPlaying==true){
            keyCheck();
            update();
            draw();
            renderer();
            //sleep 
            //std::chrono::milliseconds(500); 
            std::this_thread::sleep_for(500ms);            
        }
    }
    void Game::stop(){
        Bios::Terminal::flush();
        Bios::Terminal::clear();
        snake.stop();
        _isPlaying=false;
        _walls.clear();
        edibles.clear();
        return;
    }
    void Game::update(){//update entities
        for(size_t i=0; i<edibles.size(); i++){
            if(collisionDetection::detectCollision(snake.nextSnakeHeadPosition(),edibles[i])){
                snake.grow(edibles[i].growth());
                edibles.erase(edibles.begin() + i);
                createEdible();
            }
        }
        for(size_t i=0; i<_walls.size(); i++){
            if(collisionDetection::detectCollision(snake.nextSnakeHeadPosition(),_walls[i])){
                stop();
            }
        }
        snake.update();
    }

    void Game::renderer(void){//output canvas to renderer (terminal)
        _render->render(&canvas);
    }

    void Game::draw(){//draw entities on canvas
        canvas.clear();

        canvas.pen_color(Color::GREEN);
        //canvas.draw_pixel(snake.body());//temp canvas.draw_pixel(snake.body())
        std::vector<Point> snake_body = snake.body();
        for (size_t i = 0; i < snake_body.size(); i++) {
            canvas.draw_pixel(snake_body[i]);
        }
        canvas.pen_color(Color::RED);
        canvas.draw_pixel(snake.head());

        for (size_t i = 0; i < edibles.size(); i++) {
            canvas.pen_color(Color::WHITE);
            canvas.draw_pixel(edibles[i].point());
        }
        // working rectangle
        canvas.pen_color(Color::BLUE);
        canvas.rectangle({0, 0}, {ROWS-1,COLS-1});
    }
    /* when the game starts cool ascii title is displayed */
    void Game::StartupSign(){
        Bios::Terminal::flush();
        Bios::Terminal::clear();
        Bios::Terminal::background_color("black");
        Bios::Terminal::foreground_color("white", true);
        cout << " Sliding Slug the snake based Game application has started " <<"\r\n";
        cout << " Hit CTRL-C to stop. " <<"\r\n";
        Bios::Terminal::foreground_color("yellow", true);
        //   _____  _  _      _  _                 _____  _
        //  /  ___|| |(_)    | |(_)               /  ___|| |
        //  \ `--. | | _   __| | _  _ __    __ _  \ `--. | | _   _   __ _
        //   `--. \| || | / _` || || '_ \  / _` |  `--. \| || | | | / _` |
        //  /\__/ /| || || (_| || || | | || (_| | /\__/ /| || |_| || (_| |
        //  \____/ |_||_| \__,_||_||_| |_| \__, | \____/ |_| \__,_| \__, |
        //                                  __/ |                    __/ |
        //                                 |___/                    |___/
        cout << "   _____  _  _      _  _                 _____  _               " <<"\r\n";
        cout << "  /  ___|| |(_)    | |(_)               /  ___|| |              " <<"\r\n";
        cout << "  \u005c `--. | | _   __| | _  _ __    __ _  \u005c `--. | | _   _   __ _ " <<"\r\n";
        cout << "   `--. \u005c| || | / _` || || '_ \u005c  / _` |  `--. \u005c| || | | | / _` |" <<"\r\n";
        cout << "  /\u005c__/ /| || || (_| || || | | || (_| | /\u005c__/ /| || |_| || (_| |" <<"\r\n";
        cout << "  \u005c____/ |_||_| \u005c__,_||_||_| |_| \u005c__, | \u005c____/ |_| \u005c__,_| \u005c__, |" <<"\r\n";
        cout << "                                  __/ |                    __/ |" <<"\r\n";
        cout << "                                 |___/                    |___/ " <<"\r\n";
        Bios::Terminal::foreground_color("green", true);
    }
    void Game::keyCheck(){
        Bios::Terminal::Key key = Bios::Terminal::get_key_press();
            if (key != Bios::Terminal::Key::NONE) {
                switch (key) {
                    case Bios::Terminal::Key::LEFT:  snake.left();  break;
                    case Bios::Terminal::Key::RIGHT: snake.right(); break;
                    case Bios::Terminal::Key::UP:    snake.up();    break;
                    case Bios::Terminal::Key::DOWN:  snake.down();  break;
                    case Bios::Terminal::Key::ENTER: /*do something*/ ; break;
                    case Bios::Terminal::Key::SPACE:  stop(); break;
                    case Bios::Terminal::Key::ESC:    stop(); break;
                    case Bios::Terminal::Key::CTRL_C: exit(0); break;
                    default: break;
                }
            }

            if (key == Bios::Terminal::Key::CTRL_C) exit(0);
    }
    void Game::walls(){
        // Add corners to the walls
        _walls.push_back(Obstacle({0, 0}));
        _walls.push_back(Obstacle({0, ROWS - 1}));
        _walls.push_back(Obstacle({COLS - 1, 0}));
        _walls.push_back(Obstacle({COLS - 1, ROWS - 1}));

        // Insert walls at the edge of the square
        for (size_t i = 0; i < (ROWS); i++) {
            _walls.push_back(Obstacle({0, i}));
            _walls.push_back(Obstacle({ROWS - 1, i}));
        }
        for (size_t i = 1; i < (COLS - 1); i++) {
            _walls.push_back(Obstacle({i, 0}));
            _walls.push_back(Obstacle({i, COLS - 1}));
        }
    }
    void Game::setRenderer(IRender * render){
        _render=render;
    }
    void Game::createEdible(){
        // Generate a new edible at a random location
        size_t x = (rand()% COLS-1);
        size_t y = (rand()% ROWS-1);
        Edible newEdible({x,y}, 1);

        // Check if the new edible's location coincides with any existing wall or snake body
        bool validLocation = true;
        for(size_t i=0; i<_walls.size(); i++){
            if(collisionDetection::detectCollision(newEdible,_walls[i])){
                validLocation = false;
                break;
            }
        }
        for (const auto& bodyPart : snake.body()) {
            if (collisionDetection::detectCollision(newEdible, bodyPart)) {
                validLocation = false;
                break;
            }
        }

        // If the location is valid, add the new edible to the list
        if (validLocation==true) {
            edibles.push_back(newEdible);
        }else {
            createEdible();
        }
    }