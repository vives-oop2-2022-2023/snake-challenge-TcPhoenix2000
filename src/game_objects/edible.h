#pragma once
#include "gameObject.h"
namespace VIVES{
class Edible : public GameObject {
    private:
        Point _point;
        int growth_delta = 1;
    public:
        Edible(Point point, int growth_delta);
        int growth();
};
    inline Edible::Edible(Point point,int growth):GameObject(point){
        growth_delta = growth;
    }
    inline int Edible::growth(){
        return growth_delta;
    }
}