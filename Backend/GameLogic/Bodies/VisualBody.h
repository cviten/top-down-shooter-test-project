//
// Created by cviten on 11/23/22.
//

#ifndef TOP_DOWN_SHOOTER_VISUALBODY_H
#define TOP_DOWN_SHOOTER_VISUALBODY_H

#include "Core/Shapes.h"

template<typename Shape = Shapes::Rectangle>
class VisualBody
{
    Shape shape;
    bool active;
public:
    explicit VisualBody(const Shape& iShape, bool isActive = true) : shape(iShape), active(isActive) {}
    void setActive(bool isActive) { active = isActive;}

    const Shape& getShape() const {
        return shape;
    }

    void move(Direction direction, SpeedType speed, TimeType deltaTime) { Shapes::move(shape, direction, speed, deltaTime);}
};


#endif //TOP_DOWN_SHOOTER_VISUALBODY_H
