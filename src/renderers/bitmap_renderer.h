#pragma once

#include "../canvas.h"
#include <string>

namespace VIVES {

  class BitmapRenderer {

    public:
      BitmapRenderer(size_t width, size_t height, std::string filename="output.bmp");

    public:
      void render(Canvas * canvas);

    public:
      ~BitmapRenderer(void);

    private:
      static const unsigned int PIXEL_DEPTH = 3;
      unsigned char * buffer = nullptr;
      std::string filename;

  };

};