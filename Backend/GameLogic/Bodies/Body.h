//
// Created by cviten on 12/13/22.
//

#ifndef TOP_DOWN_SHOOTER_BODY_H
#define TOP_DOWN_SHOOTER_BODY_H

#include "Core/Core.h"
#include "Core/CoreTypes.h"
#include "Core/Shapes.h"

template<typename Shape>
class Body
{
protected:
    Shape shape;
    bool active;
public:
    explicit Body(const Shape& iShape, bool isActive = true) : shape(iShape), active(isActive) {}

    void setActive(bool isActive) { active = isActive;}
    bool isActive() const {
        return active;
    }

    Point getPosition() const { return shape.position; }
    Point getCenter() const { return  shape.center(); }

    const Shape& getShape() const {
        return shape;
    }

    void move(Direction direction, SpeedType speed, TimeType deltaTime) { Shapes::move(shape, direction, speed, deltaTime);}
};


#endif //TOP_DOWN_SHOOTER_BODY_H
