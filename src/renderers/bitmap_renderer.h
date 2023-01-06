#pragma once

#include <string>
#include <vector>

#include "../helpers/bitmap_generator.h"
#include "../canvas.h"

#include "render_interface.h"
namespace VIVES {

  class BitmapRenderer: public IRender{

    public:
      BitmapRenderer(std::string filename="./bin/output.bmp");

    public:
      void render(Canvas * canvas)override;

    public:
      ~BitmapRenderer(void);

    private:
      static const unsigned int PIXEL_DEPTH = 3;
      unsigned char * buffer = nullptr;
      std::string filename;

  };

};