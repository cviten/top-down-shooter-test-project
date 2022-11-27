//
// Created by cviten on 11/23/22.
//

#ifndef TOP_DOWN_SHOOTER_VISUALBODY_H
#define TOP_DOWN_SHOOTER_VISUALBODY_H

#include "../../../Core/Shapes.h"

class VisualBody {
    Shapes::Rectangle rect;
    bool active;
public:
    explicit VisualBody(const Shapes::Rectangle& rect, bool isActive = true) : rect(rect), active(isActive) {}
    void setActive(bool isActive) { active = isActive;}

    const Shapes::Rectangle& getShape() const {
        return rect;
    }
    void move(Direction direction, SpeedType speed, TimeType deltaTime) { Shapes::move(rect, direction, speed, deltaTime);}

};

//template<typename Shape = Shapes::Rectangle>
//class VisualBody
//{
//    Shape shape;
//    bool active;
//public:
//    explicit VisualBody(const Shape& rect, bool isActive = true) : shape(shape), active(isActive) {}
//    void setActive(bool isActive) { active = isActive;}
//
//    const Shape& getShape() const {
//        return shape;
//    }
//
//    void move(Direction direction, SpeedType speed, TimeType deltaTime) { Shapes::move(shape, direction, speed, deltaTime);}
//};


#endif //TOP_DOWN_SHOOTER_VISUALBODY_H
