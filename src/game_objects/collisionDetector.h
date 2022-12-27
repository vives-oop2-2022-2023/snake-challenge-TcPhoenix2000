#pragma once

#include "../point.h"
#include "./obstacle.h"

namespace GameObject{
    class collisionDetection{
    public:
       static bool detectCollision(GameObject object1, GameObject object2){
            return (object1.point().x==object2.point().x)&&(object1.point().y==object2.point().y);
       }
    };
}