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
//# + equals(Color:color): bool
//#################################
#pragma once
namespace VIVES{
    class Color{
        private:
            unsigned char red_ = 0, green_ = 0 , blue_ = 0;

        public:
            Color(void);
            Color(unsigned char red,unsigned char green,unsigned char blue);

            unsigned char red()const;
            unsigned char green()const;
            unsigned char blue()const;

            void red(unsigned char red);
            void green(unsigned char green);
            void blue(unsigned char blue);

        public:
            bool equals(Color color)const;

        public:
            static const Color BlACK;
            static const Color WHITE;
            static const Color RED;
            static const Color GREEN;
            static const Color BLUE;
    };
}