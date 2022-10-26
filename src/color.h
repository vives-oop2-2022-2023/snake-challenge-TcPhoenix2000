//#################################
//# Color
//#################################
//# - red: unsigned char
//# - green: unsigned char
//# - blue: unsigned char
//#################################
//# + Color()
//# + Color(red: unsigned char, green: unsigned char, blue: unsigned char)
//# + red(): unsigned char
//# + green(): unsigned char
//# + blue(): unsigned char
//# + red(red: unsigned char)
//# + green(green: unsigned char)
//# + blue(blue: unsigned char)
//#################################
#pragma once
class Color{
    private:
        unsigned char red , green , blue;
    public:
        Color(void);
        Color(unsigned char red,unsigned char green,unsigned char blue);
        unsigned char red();
        unsigned char green();
        unsigned char blue();
        unsigned char red(unsigned char red);
        unsigned char green(unsigned char green);
        unsigned char blue(unsigned char blue);

};