#include "color.h"

using namespace VIVES;
    Color::Color(void){

    }
    Color::Color(unsigned char red,unsigned char green,unsigned char blue){
        this->red(red);
        this->green(green);
        this->blue(blue);
    } 
    unsigned char Color::red()const{
        return red_;
    }
    unsigned char Color::green()const{
        return green_;
    }
    unsigned char Color::blue()const{
        return blue_;
    }
    void Color::red(unsigned char red){
        this->red_=red;
    }
    void Color::green(unsigned char green){
        this->green_=green; 
    }
    void Color::blue(unsigned char blue){
        this->blue_=blue;
    }
    bool Color::equals(Color color)const{
        this->red()== color.red() && 
        this->green()== color.green() && 
        this->blue()== color.blue();
    }
    const Color Color::BlACK = Color(0,0,0);
    const Color Color::WHITE = Color(255,255,255);
    const Color Color::RED   = Color(255,0,0);
    const Color Color::GREEN = Color(0,255,0);
    const Color Color::BLUE  = Color(0,0,255);
