//#################################
//# TextRenderer()
//#################################
//# + render(canvas * Canvas)      
//#################################

#pragma once
#include "../canvas.h"
#include "../point.h"

#include "render_interface.h"

namespace VIVES {
    class TextRenderer : public IRender {
        public:
            void render(Canvas * canvas);
    };
}