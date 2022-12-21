// compile with make
// run with :  ./bin/program
#include <iostream>
#include "./lib/terminal.h"
#include "game.h" 

using namespace std;

VIVES::Game game;
int main(){
    Bios::Terminal::flush();
    Bios::Terminal::clear();
    cout << " Sliding Slug the snake based Game application has started " << endl;
    cout << " Hit CTRL-C to stop. " << endl;
    game.StartupSign();

    game.start();
  return 0;
}