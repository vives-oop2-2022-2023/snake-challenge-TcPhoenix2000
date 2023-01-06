#include "bitmap_renderer.h"

namespace VIVES {

  BitmapRenderer::BitmapRenderer(std::string filename)
  : filename(filename) {

  }

  BitmapRenderer::~BitmapRenderer(void) {
    delete[] buffer;
    buffer = nullptr;
  }

  void BitmapRenderer::render(Canvas * canvas) {
    buffer = new unsigned char[canvas->width() * canvas->height() * PIXEL_DEPTH];
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