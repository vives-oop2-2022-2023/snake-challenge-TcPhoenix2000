#pragma once
#include "../canvas.h"
namespace VIVES{
  class IRender {
    public:
    virtual void render(Canvas *canvas) = 0;
  };
}