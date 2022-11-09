#include "TextRenderer.h"

#include <sstream>
#include <iostream>

namespace VIVES{
    void TextRenderer::render(Canvas * canvas){

        std::stringstream output;
        for(size_t y = 0; y < canvas->height();y++){
            for(size_t x = 0; x < canvas->width();x++){
            
                //color to  string?
                if (canvas->pixel({x,y}).equals(Color::RED)){
                    output << "@";
                } else if (canvas->pixel({x,y}).equals(Color::GREEN)){
                    output << "█";
                } else {
                    output << " ";
                }
            }
            output << std::endl;
        }
        system("clear");
        std::cout << output.str();
    }  
}