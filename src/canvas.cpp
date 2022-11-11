#include "canvas.h"

using namespace std;
using namespace VIVES;

    Canvas::Canvas(size_t width, size_t height){
        _buffer.resize(width);
        for(size_t i = 0; i < width; i++){
            _buffer[i].resize(height);
        }
    }
    void Canvas::clear(void){
        pen_color(Color::BlACK);
        for (auto & line : _buffer) {
            for (auto & element : line) {
                element = penColor;
            }
        }
    }
    void Canvas::pen_color(Color color){
        this->penColor = color;
    }
    void Canvas::draw_pixel(Point point){
        _buffer[point.x][point.y]=penColor;
    }
    void Canvas::horizontal_line(Point origin,unsigned int length ){
        for(unsigned int i = origin.x; i < length; i++){
            origin.x = i;
            draw_pixel(origin);
        }
    }
    void Canvas::vertical_line(Point origin, unsigned int length){
        for(unsigned int i = origin.y; i < length; i++){
            origin.y = i;
            draw_pixel(origin);
        }
    }
    void Canvas::rectangle(Point origin,Point second){
        horizontal_line(origin,second.x);
        horizontal_line({origin.x,second.y},second.x);
        vertical_line(origin,second.y);
        vertical_line({second.x,origin.y},second.y);
        draw_pixel(second);
    }
    Color Canvas::pixel(Point point){
        return _buffer[point.x][point.y];
    }
    size_t Canvas::width(){
        return _buffer.size();
    }
    size_t Canvas::height(){
        return _buffer[0].size();
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
    */
