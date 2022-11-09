//#################################
//# Canvas
//#################################
//# - _buffer: std::Vector<std::vector<Color>>
//# - penColor: Color
//#################################
//# + Canvas(with:size_t ,height :size_t)
//# + clear()
//# + pen_color(color: Color)       set the active drawing color
//# + draw_pixel(point: Point)
//# + horizontal_line(origin: Point, length: unsigned int)
//# + vertical_line(origin: Point, length: unsigned int)
//# + rectangle(origin: Point, second: Point)
//#
//# + pixel(point: Point) :color
//# + width() size_t
//# + height() size_t
//#################################
#pragma once
#include <iostream>
#include <vector>

#include "point.h"
#include "color.h"

namespace VIVES{
    class Canvas{
        public:
            Canvas(size_t width, size_t height);
        private:
            std::vector<std::vector<Color>> _buffer;
            Color penColor=Color::WHITE;
        public:
            void clear(void);
            void pen_color(Color color);       //set the active drawing color
            void draw_pixel(Point point);
            void horizontal_line(Point origin,unsigned int length );
            void vertical_line(Point origin, unsigned int length);
            void rectangle(Point origin,Point second);
            
            Color pixel(Point point);
            size_t width();
            size_t height();
    };
}