//
// Created by cviten on 11/20/22.
//

#ifndef TOP_DOWN_SHOOTER_COLLISIONBODY_H
#define TOP_DOWN_SHOOTER_COLLISIONBODY_H

#include "Body.h"

class CollisionBody : public Body<Shapes::Rectangle> {
public:
    explicit CollisionBody(const Shapes::Rectangle& rect, bool isActive = true) : Body(rect, isActive) {}
    explicit CollisionBody(const Shapes::Circle& circle, bool isActive = true) : Body({circle.position, 2 * circle.radius}, isActive) {
        using namespace Shapes;
        const Type sqrLength = squareLengthOfSameAreaCircle(circle.radius);
        shape.position.x += circle.radius - sqrLength * 0.5;
        shape.position.y += circle.radius - sqrLength * 0.5;
        shape.size = sqrLength;
    }

    static bool check(const CollisionBody& body1, const CollisionBody& body2)
    {
        using namespace Shapes;
        if ( !(body1.active && body2.active) ) return false;
        return isRectangleValid(Rectangle::intersection(body1.shape, body2.shape));
    }

};

#endif //TOP_DOWN_SHOOTER_COLLISIONBODY_H
