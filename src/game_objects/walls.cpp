#include "walls.h"

using namespace GameObject;

Walls::Walls(size_t rows, size_t cols): Obstacle(Point(0,0)){
    // Insert walls at the edge of the square
    for (int i = 0; i < static_cast<int>(rows); i++) {
        walls.push_back(new Obstacle(Point(0, i)));
        walls.push_back(new Obstacle(Point(cols - 1, i)));
    }
    for (int i = 1; i < static_cast<int>(cols - 1); i++) {
        walls.push_back(new Obstacle(Point(i, 0)));
        walls.push_back(new Obstacle(Point(i, rows - 1)));
    }
    
    // Add corners to the walls
    walls.push_back(new Obstacle(Point(0, 0)));
    walls.push_back(new Obstacle(Point(0, rows - 1)));
    walls.push_back(new Obstacle(Point(cols - 1, 0)));
    walls.push_back(new Obstacle(Point(cols - 1, rows - 1)));
}

bool Walls::collidesWith(Obstacle& other) {
    // Check if the other obstacle collides with this walls object
    return false;
}