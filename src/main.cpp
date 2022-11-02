// compile with make
// run with :  ./bin/program
#include <iostream>

#include <array>
#include <string>

//#include "game.h"


//temp default settings for canvas size
#define COLS 128
#define ROWS 10

using namespace std;


int main(){
    cout << " Sliding Slug the snake based Game application has started" << endl;

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