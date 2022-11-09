// compile with make
// run with :  ./bin/program
#include <iostream>

#include "game.h"
//temp include of terminal unless using specified color in terminal before starting the game 
//#include "terminal.h"


using namespace std;
//using namespace Bios;
using namespace VIVES;

int main(){
    cout << " Sliding Slug the snake based Game application has started" << endl;
    Game();
    return 0;
}

/*
    //temp include files array and string
    #include <array>
    #include <string>
    //temp////////////////////////////////
    ///// tried some stuff with 2d array
    std::array<std::array<std::string, COLS>, ROWS> _buffer;
        // Render table
            //┌───┐
            //│...│
            //│...│
            //│...│
            //│...│
            //└───┘
            //head ▲ 
            //body █
            _buffer[2][3]="▲";
            _buffer[3][3]="█";
            _buffer[4][3]="█";
            _buffer[5][3]="█";

        cout <<"┌";
        for (int i = 0; i < COLS; i++)
        cout <<"─";
        cout <<"─"<< endl;//┐

        for (auto & line : _buffer) {
            cout <<"│";
            for (auto & element : line) {
            cout << element << " ";

            }
            cout << endl;
        }

        cout <<"└";
        for (int i = 0; i < COLS; i++)
        cout <<"─";
        cout <<"─"<< endl;//┘
        */