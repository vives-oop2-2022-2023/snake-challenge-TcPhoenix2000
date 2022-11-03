// compile with make
// run with :  ./bin/program
#include <iostream>

//temp include files array and string
#include <array>
#include <string>

#include "game.h"
#include "terminal.h"


using namespace std;
using namespace Bios;

int main(){
    cout << " Sliding Slug the snake based Game application has started" << endl;
    
    Terminal::foreground_color("green",5);

    std::array<std::array<std::string, COLS>, ROWS> _buffer;
        // Render table
            //┌───┐
            //│...│
            //│...│
            //│...│
            //│...│
            //└───┘
        cout <<"┌";
        for (int i = 0; i < COLS; i++)
        cout <<"─";
        cout <<"┐"<< endl;

        for (auto & line : _buffer) {
            cout <<"│";
            for (auto & element : line) {
            cout << element << ".";

            }
            cout << "│" << endl;
        }

        cout <<"└";
        for (int i = 0; i < COLS; i++)
        cout <<"─";
        cout <<"┘"<< endl;
    return 0;
}