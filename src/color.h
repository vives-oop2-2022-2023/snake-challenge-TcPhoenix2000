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
namespace VIVES{
    class Color{
        private:
            unsigned char red_ , green_ , blue_;
        public:
            Color(void);
            Color(unsigned char red,unsigned char green,unsigned char blue);
            unsigned char red();
            unsigned char green();
            unsigned char blue();
            void red(unsigned char red);
            void green(unsigned char green);
            void blue(unsigned char blue);

    };
}