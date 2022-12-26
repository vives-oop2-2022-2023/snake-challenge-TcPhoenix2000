// compile with make
// run with :  ./bin/program
#include <iostream>
#include <string>
#include "./lib/terminal.h"
#include "./lib/gameMenu.h"
#include "game.h" 

VIVES::Game game;
int main(){
    Bios::Terminal::flush();
    Bios::Terminal::clear();
    Bios::Terminal::background_color("black");
    std::cout << " Sliding Slug the snake based Game application has started " << std::endl;
    std::cout << " Hit CTRL-C to stop. " << std::endl;
    Bios::Terminal::foreground_color("yellow", true);
    game.StartupSign();
    //Bios::Terminal::foreground_color("green", true);
    //Linked_List::gameMenu::displayMenu menu;
    game.start();
  return 0;
}