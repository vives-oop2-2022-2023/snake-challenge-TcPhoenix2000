#pragma once
#include "gameObject.h"

namespace VIVES{
    class collisionDetection{
    public:
       static bool detectCollision(GameObject object1, GameObject object2){
            return (object1.point().x==object2.point().x)&&(object1.point().y==object2.point().y);
        }
        static bool detectCollision(Point point, GameObject object2){
            return (point.x==object2.point().x)&&(point.y==object2.point().y);
        }
    };
}