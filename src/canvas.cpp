#include "canvas.h"

using namespace std;

    //┌───┐
    //| . |
    //└───┘

    Canvas::Canvas(void){
        
    }
    void Canvas::clear(void){

    }
    void Canvas::pen_color(Color color){

    }       
    void Canvas::pixel(Point point){
        // pixel 
    }
    void Canvas::horizontal_line(Point Origin,unsigned int length ){
        //horizontal ─── 
    }
    void Canvas::vertical_line(Point origin, unsigned int length){
        //vertical │

    }
    void Canvas::rectangle(Point origin,Point second){
        //top corners    ┌ ┐
        //bottom corners └ ┘
    }
    std::array<std::array<Color,COLS>,ROWS> Canvas::buffer(){
        /*std::array<std::array<std::string, COLS>, ROWS> _buffer;
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
        cout <<"┘"<< endl;*/
        return buffer();
    }
