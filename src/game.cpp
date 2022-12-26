#include "game.h"
#include "./lib/terminal.h"
#include "./game_objects/edible.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace VIVES;
using namespace GameObject;

const int ROWS=40;
const int COLS=15;
    Game::Game(void):canvas(ROWS,COLS){
    }
    void Game::start(){
        Bios::Terminal::flush();
        Bios::Terminal::clear();
        Bios::Terminal::hide_cursor();

        snake.start();
        while (_isPlaying){
            update();
            collisionDetect();
            draw();
            render();
            //sleep 
            std::this_thread::sleep_for(100ms);           
        }
    }
    void Game::collisionDetect(){
        Point nextHeadPos = snake.nextSnakeHeadPosition();
        // Check for collision with walls
        if (nextHeadPos.x < 0 || nextHeadPos.x >= COLS || nextHeadPos.y < 0 || nextHeadPos.y >= ROWS) {
            // Handle wall collision (e.g. end the game)
            snake.stop();
        }

        // Check for collision with snake body
        std::vector<Point> snake_body = snake.body();
        for (int i = 1; i < (int)snake_body.size(); i++) {
            if (nextHeadPos.x == snake_body[i].x && nextHeadPos.y == snake_body[i].y) {
                // Handle snake body collision (e.g. end the game)
                snake.stop();
            }
        }

        // Check for collision with obstacles
        for (auto &obstacle : obstacles) {
            Obstacle* tempObject = new Obstacle(nextHeadPos);
            if (obstacle.collidesWith(*tempObject)) {
            // Collision detected
            }
            delete tempObject;
        }

        // Check for collision with edibles
        for (auto &edible : obstacles) {
        // Declare and construct a new Edible object
        Edible *tempObject = new Edible(nextHeadPos);
        if (edible.collidesWith(*tempObject)) {
                //snake.grow();
                delete tempObject;
                return;
            }
            delete tempObject;
        }
    }

    
    void Game::update(){//update entities 
            Bios::Terminal::Key key = Bios::Terminal::get_key_press();
            if (key != Bios::Terminal::Key::NONE) {
                //Terminal::clear();
                switch (key) {
                    case Bios::Terminal::Key::LEFT:  snake.left();  break;
                    case Bios::Terminal::Key::RIGHT: snake.right(); break;
                    case Bios::Terminal::Key::UP:    snake.up();    break;
                    case Bios::Terminal::Key::DOWN:  snake.down();  break;
                    case Bios::Terminal::Key::ENTER: /*do something*/ ; break;
                    case Bios::Terminal::Key::SPACE: /*do something*/ ; break;
                    case Bios::Terminal::Key::ESC: snake.stop(); _isPlaying = false; break;
                }
            }

            if (key == Bios::Terminal::Key::CTRL_C) exit(0);
        
        snake.update();
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
        // working rectangle
        canvas.pen_color(Color::BLUE);
        canvas.rectangle({0, 0}, {ROWS-1,COLS-1});
    }
    void Game::render(void){//output canvas to renderer (terminal)
        text_renderer.render(&canvas);
        //bitmap.render(&canvas);
    }
    
    /* when the game starts cool ascii title is displayed */
    void Game::StartupSign(){
        //   _____  _  _      _  _                 _____  _
        //  /  ___|| |(_)    | |(_)               /  ___|| |
        //  \ `--. | | _   __| | _  _ __    __ _  \ `--. | | _   _   __ _
        //   `--. \| || | / _` || || '_ \  / _` |  `--. \| || | | | / _` |
        //  /\__/ /| || || (_| || || | | || (_| | /\__/ /| || |_| || (_| |
        //  \____/ |_||_| \__,_||_||_| |_| \__, | \____/ |_| \__,_| \__, |
        //                                  __/ |                    __/ |
        //                                 |___/                    |___/
        cout << "   _____  _  _      _  _                 _____  _               " << endl;
        cout << "  /  ___|| |(_)    | |(_)               /  ___|| |              " << endl;
        cout << "  \u005c `--. | | _   __| | _  _ __    __ _  \u005c `--. | | _   _   __ _ " << endl;
        cout << "   `--. \u005c| || | / _` || || '_ \u005c  / _` |  `--. \u005c| || | | | / _` |" << endl;
        cout << "  /\u005c__/ /| || || (_| || || | | || (_| | /\u005c__/ /| || |_| || (_| |" << endl;
        cout << "  \u005c____/ |_||_| \u005c__,_||_||_| |_| \u005c__, | \u005c____/ |_| \u005c__,_| \u005c__, |" << endl;
        cout << "                                  __/ |                    __/ |" << endl;
        cout << "                                 |___/                    |___/ " << endl;
        std::this_thread::sleep_for(2000ms);
    }