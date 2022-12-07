#include "game.h"
#include "terminal.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace Bios;
using namespace VIVES;

const int ROWS=40;
const int COLS=10;
    Game::Game(void):canvas(ROWS,COLS){
        //StartupSign();
        //start();
    }
    void Game::start(){
        Terminal::flush();
        Terminal::clear();
        Terminal::hide_cursor();
        Terminal::background_color("black");
        Terminal::foreground_color("yellow", true);

        snake.start();
        while (_isPlaying){
            update();
            draw();
            render();
            //sleep 
            std::this_thread::sleep_for(100ms);           
        }
    }
    void Game::update(){//update entities
        //#this function generates mem rerror 
        
            Terminal::Key key = Terminal::get_key_press();
            if (key != Terminal::Key::NONE) {
                //Terminal::clear();
                switch (key) {
                    case Terminal::Key::LEFT:  snake.left();  break;
                    case Terminal::Key::RIGHT: snake.right(); break;
                    case Terminal::Key::UP:    snake.up();    break;
                    case Terminal::Key::DOWN:  snake.down();  break;
                    /*  
                        case Terminal::Key::ENTER:; break;
                        case Terminal::Key::SPACE: cout << "You pressed SPACE" ; break;
                        case Terminal::Key::ESC: cout << "You pressed ESC" ; break;
                    */
                }
            }

            if (key == Terminal::Key::CTRL_C) exit(0);
        
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
        //BitmapRenderer(size_t width ,size_t height ,std::string filename);
        text_renderer.render(&canvas);
    }

    //head @ 
    //body █
    
    void Game::StartupSign(){
        //when the game starts cool ascii title is displayed 
        //    _____  _  _      _  _                 _____  _
        //  /  ___|| |(_)    | |(_)               /  ___|| |
        //  \ `--. | | _   __| | _  _ __    __ _  \ `--. | | _   _   __ _
        //   `--. \| || | / _` || || '_ \  / _` |  `--. \| || | | | / _` |
        //  /\__/ /| || || (_| || || | | || (_| | /\__/ /| || |_| || (_| |
        //  \____/ |_||_| \__,_||_||_| |_| \__, | \____/ |_| \__,_| \__, |
        //                                  __/ |                    __/ |
        //                                  |___/                    |___/
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