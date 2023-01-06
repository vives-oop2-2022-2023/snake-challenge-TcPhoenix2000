//#################################
//# TextRenderer()
//#################################
//# + render(canvas * Canvas)      
//#################################

#pragma once
#include "../canvas.h"
#include "../point.h"

#include "../lib/terminal.h"
#include <sstream>
#include "render_interface.h"

namespace VIVES {
    class TextRenderer : public IRender {
        public:
            void render(Canvas * canvas)override;
    };
}