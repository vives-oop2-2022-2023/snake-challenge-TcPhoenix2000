#include "game.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace VIVES;
const int ROWS=40;
const int COLS=20;
    Game::Game(void):canvas(ROWS,COLS){
        StartupSign();
        std::this_thread::sleep_for(2000ms);
        start();
    }
    void Game::start(){
        while (_isPlaying){
            update();
            draw();
            render();
            //sleep 
            std::this_thread::sleep_for(100ms);           
        }
    }
    void Game::update(){//update entities

    }
    void Game::draw(){//draw entities on canvas
        canvas.clear();
        canvas.pen_color(Color::RED);
        canvas.draw_pixel({2,6});//temp for canvas.draw_pixel(snake.head())
        canvas.pen_color(Color::GREEN);
        canvas.draw_pixel({2,5});//temp canvas.draw_pixel(snake.body())
        /*
        std::vector<Point> Snake = snake.body();
        for (size_t i = 0; i < Snake.size(); i++) {
            canvas.draw_pixel(Snake[i]);
        }*/

        canvas.pen_color(Color::BLUE);
        canvas.rectangle({0, 0}, {ROWS-1,COLS-1});
    }
    void Game::render(void){//output canvas to renderer (terminal)
        //bitmap.generate( png,);
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
    }