// compile with make
// run with :  ./bin/program
#include <iostream>
#include <chrono>
#include <thread>

#include "game.h" 
#include "snake.h"
#include "terminal.h"


using namespace std;
using namespace Bios;
using namespace VIVES;
Game game;
Snake snake;
int main(){
    cout << " Sliding Slug the snake based Game application has started" << endl;
    cout << "Hit CTRL-C to stop." << endl;
    game.StartupSign();
    Terminal::flush();
    Terminal::clear();
    Terminal::hide_cursor();
    Terminal::background_color("black");
    Terminal::foreground_color("yellow", true);

    game.start();
    while (true) {
        Terminal::Key key = Terminal::get_key_press();
        if (key != Terminal::Key::NONE) {
        Terminal::clear();
        switch (key) {
            case Terminal::Key::LEFT:  snake.left();  break;
            case Terminal::Key::RIGHT: snake.right(); break;
            case Terminal::Key::UP:    snake.up();    break;
            case Terminal::Key::DOWN:  snake.down();  break;
            case Terminal::Key::ENTER: cout << "You pressed ENTER" << endl; break;
            case Terminal::Key::SPACE: cout << "You pressed SPACE" << endl; break;
            case Terminal::Key::ESC: cout << "You pressed ESC" << endl; break;
        }
        }

        if (key == Terminal::Key::CTRL_C) exit(0);
    }
  return 0;
}