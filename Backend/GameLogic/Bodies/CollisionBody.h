//
// Created by cviten on 11/20/22.
//

#ifndef TOP_DOWN_SHOOTER_COLLISIONBODY_H
#define TOP_DOWN_SHOOTER_COLLISIONBODY_H

#include "Core/Shapes.h"

class CollisionBody {
    Shapes::Rectangle rect;
    bool active;
public:
    explicit CollisionBody(const Shapes::Rectangle& rect, bool isActive = true) : rect(rect), active(isActive) {}
    explicit CollisionBody(const Shapes::Circle& circle, bool isActive = true) : rect(circle.position, 2 * circle.radius), active(isActive) {
        using namespace Shapes;
        const Type sqrLength = squareLengthOfSameAreaCircle(circle.radius);
        rect.position.x += circle.radius - sqrLength * 0.5;
        rect.position.y += circle.radius - sqrLength * 0.5;
        rect.size = sqrLength;
    }

    Point getPosition() const { return rect.position; }

    static bool check(const CollisionBody& body1, const CollisionBody& body2)
    {
        using namespace Shapes;
        if ( !(body1.active && body2.active) ) return false;
        return isRectangleValid(Rectangle::intersection(body1.rect, body2.rect));
    }

    void setActive(bool isActive) { active = isActive;}

    void move(Direction direction, SpeedType speed, TimeType deltaTime) { Shapes::move(rect, direction, speed, deltaTime);}
};


#endif //TOP_DOWN_SHOOTER_COLLISIONBODY_H
