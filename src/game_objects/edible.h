#pragma once
#include "obstacle.h"

namespace GameObject {
class Edible : public Obstacle {
public:
Edible(Point point);
bool collidesWith(Obstacle& other) override;
};
}