//#################################
//# Canvas
//#################################
//# - _buffer: std::array<std::array<Color>>
//# - penColor: Color
//#################################
//# + Canvas()
//# + clear()
//# + pen_color(color: Color)       set the active drawing color
//# + pixel(point: Point)
//# + horizontal_line(origin: Point, length: unsigned int)
//# + vertical_line(origin: Point, length: unsigned int)
//# + rectangle(origin: Point, second: Point)
//# + buffer(): std::array<std::array<Color>>
//################################
#pragma once
#include <array>
#include <point.h>
#include <color.h>

class Canvas{
    private:
        std::array<std::array<Color,20>,20> _buffer;
        Color penColor ;

    public:
        Canvas(void);
        void clear(void);
        void pen_color(Color color);       //set the active drawing color
        void pixel(Point point);
        void horizontal_line(Point Origin,unsigned int length );
        void vertical_line(Point origin, unsigned int length);
        void rectangle(Point origin,Point second);
        std::array<std::array<Color,20>,20> buffer();
};