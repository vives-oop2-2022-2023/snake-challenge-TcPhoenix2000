#include "edible.h"

using namespace GameObject;

Edible::Edible(Point point): Obstacle(point) {
// Initialize the edible object
}

bool Edible::collidesWith(Obstacle& object) {
// Check if the object collides with this edible object
return false;
}