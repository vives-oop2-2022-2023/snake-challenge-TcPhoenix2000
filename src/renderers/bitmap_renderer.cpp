#include "bitmap_renderer.h"

#include <vector>
#include "../color.h"
#include "../helpers/bitmap_generator.h"

namespace VIVES {

  BitmapRenderer::BitmapRenderer(size_t width, size_t height, std::string filename)
  : filename(filename) {

    buffer = new unsigned char[width * height * PIXEL_DEPTH];
  }

  BitmapRenderer::~BitmapRenderer(void) {
    delete[] buffer;
    buffer = nullptr;
  }

  void BitmapRenderer::render(Canvas * canvas) {
    unsigned char * pBuffer = buffer;

    // Default origin of BMP is bottom left corner, so we count down y
    for (unsigned int y = canvas->height()-1; y > 0; y--) {
      for (unsigned int x = 0; x < canvas->width(); x++) {
        pBuffer[0] = canvas->pixel({ x, y }).blue();
        pBuffer[1] = canvas->pixel({ x, y }).green();
        pBuffer[2] = canvas->pixel({ x, y }).red();
        pBuffer += 3;
      }
    }

    BitmapGenerator::generate(buffer, canvas->height(), canvas->width(), filename.c_str());
  }

};