#pragma once
#include "obstacle.h"
#include <vector>

namespace GameObject {
class Walls : public Obstacle {
public:
  Walls(size_t rows, size_t cols);
  bool collidesWith(Obstacle& other) override;

private:
  std::vector<Obstacle*> walls;
};
}