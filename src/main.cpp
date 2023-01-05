// compile with make
// run with :  ./bin/program
#include <iostream>
#include <string>
#include "./lib/gameMenu.h"
#include "game.h" 

VIVES::Game game;
int main(){
  while (true) {
    game.StartupSign();
    Linked_List::displayMenu();
  }
  return 0;
}