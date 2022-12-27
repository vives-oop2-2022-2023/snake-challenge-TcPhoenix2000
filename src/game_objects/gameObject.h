#pragma once
#include "../point.h"

namespace VIVES{
    class GameObject
    {
    private:
        Point _point;
    public:
        GameObject(Point point);
        Point point();
        void point(Point point);
        
    };
    
    inline GameObject::GameObject(Point point){
        _point = point;
    }
    inline Point GameObject::point(){
        return _point;
    }
    inline void GameObject::point(Point point){
        _point= point;
    }
}