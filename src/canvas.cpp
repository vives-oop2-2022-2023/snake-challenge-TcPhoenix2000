#include "canvas.h"

using namespace std;
using namespace VIVES;

    Canvas::Canvas(size_t width, size_t height){

    }
    void Canvas::clear(void){

    }
    void Canvas::pen_color(Color color){

    }       //set the active drawing color
    void Canvas::draw_pixel(Point point){
        _buffer[point.x][point.y]=penColor;
    }
    void Canvas::horizontal_line(Point Origin,unsigned int length ){

    }
    void Canvas::vertical_line(Point origin, unsigned int length){

    }
    void Canvas::rectangle(Point origin,Point second){

    }
    Color Canvas::pixel(Point point){

    }
    size_t Canvas::width(){
        _buffer.size();
    }
    size_t Canvas::height(){
        _buffer[0].size();
    }
    /*
        //horizontal ─── 
        //vertical │
        //top corners    ┌ ┐
        //bottom corners └ ┘
        // Render table
            //┌───┐
            //│...│
            //│...│
            //│...│
            //│...│
            //└───┘
        

        for (auto & line : _buffer) {
            for (auto & element : line) {
                cout << element << ".";
            }
            cout << endl;
        }
        return buffer();
    }*/
