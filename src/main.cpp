// compile with make
// run with :  ./bin/program
#include <iostream>
#include "game.h" 

using namespace std;
using namespace VIVES;

Game game;
int main(){
    cout << " Sliding Slug the snake based Game application has started" << endl;
    cout << "Hit CTRL-C to stop." << endl;
    game.StartupSign();

    game.start();
  return 0;
}