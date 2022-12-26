#include "obstacle.h"

GameObject::Obstacle::Obstacle(Point point) : point(point) {}

bool GameObject::Obstacle::collidesWith(Obstacle& other) {
    // Check if this obstacle collides with the other obstacle
    return false;
}