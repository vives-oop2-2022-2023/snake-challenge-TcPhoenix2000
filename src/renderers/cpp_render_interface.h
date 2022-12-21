#include "canvas.h"
#include "renderers/bitmap_renderer.h"
#include "renderers/TextRenderer.h"
namespace VIVES{
class IRender {
  virtual void render(Canvas *canvas) = 0;
};

///////////////////////////////////////////////////

class SenseHatRenderer : public IRender {

  void render(Canvas * canvas) override {
    // ....
  }

};

///////////////////////////////////////////////////

// SenseHatRenderer renderer;
IRender * renderer = new SenseHatRenderer();
//renderer->render();
}