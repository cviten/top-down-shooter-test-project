//
// Created by cviten on 11/23/22.
//

#ifndef TOP_DOWN_SHOOTER_VISUALBODY_H
#define TOP_DOWN_SHOOTER_VISUALBODY_H

#include "Body.h"

template<typename Shape = Shapes::Rectangle>
class VisualBody : public Body<Shape>
{
public:
    explicit VisualBody(const Shape& iShape, bool isActive = true) : Body<Shape>(iShape, isActive)  {}
};


#endif //TOP_DOWN_SHOOTER_VISUALBODY_H
