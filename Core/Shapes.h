//
// Created by cviten on 11/19/22.
//

#ifndef TOP_DOWN_SHOOTER_SHAPES_H
#define TOP_DOWN_SHOOTER_SHAPES_H

#include <cmath>

#include "core.h"
#include "CoreTypes.h"

namespace Shapes
{
    struct Rectangle
    {
        Point position; // Counted from the top left
        Size size;
        Point bottomRight() const { return position + size; }
        Rectangle(Point pos, Size size) : position(pos), size(size) {}
        static Rectangle intersection(const Rectangle& rect1, const Rectangle& rect2)
        {
            ;
            ;
            if (((rect1.position.x > rect2.bottomRight().x) || (rect1.position.y > rect2.bottomRight().y) ||
                (rect2.position.y > rect1.bottomRight().y) || (rect2.position.x > rect1.bottomRight().x)))
                return {{},{}};

            // To not get depend on '<algorithm>' (Source: SFML/Rect.inl)
            const auto min = [](Type a, Type b) { return (a < b) ? a : b; };
            const auto max = [](Type a, Type b) { return (a < b) ? b : a; };

            const Type r1MinX = min(rect1.position.x, rect1.position.x + rect1.size.x);
            const Type r1MaxX = max(rect1.position.x, rect1.position.x + rect1.size.x);
            const Type r1MinY = min(rect1.position.y, rect1.position.y + rect1.size.y);
            const Type r1MaxY = max(rect1.position.y, rect1.position.y + rect1.size.y);

            // Compute the min and max of the second rectangle on both axes
            const Type r2MinX = min(rect2.position.x, rect2.position.x + rect2.size.x);
            const Type r2MaxX = max(rect2.position.x, rect2.position.x + rect2.size.x);
            const Type r2MinY = min(rect2.position.y, rect2.position.y + rect2.size.x);
            const Type r2MaxY = max(rect2.position.y, rect2.position.y + rect2.size.x);

            // Compute the intersection boundaries
            const Type interLeft   = max(r1MinX, r2MinX);
            const Type interTop    = max(r1MinY, r2MinY);
            const Type interRight  = min(r1MaxX, r2MaxX);
            const Type interBottom = min(r1MaxY, r2MaxY);

            if ((interLeft < interRight) && (interTop < interBottom))
            {
                return Rectangle({interLeft, interTop}, {interRight - interLeft, interBottom - interTop});
            }
            else
            {
                return {{},{}};
            }
        }
    };

    inline bool isRectangleValid(const Rectangle& rect) { return checkCoordQuad(rect.size) == CoordQuad::PosXY; }

    struct Circle
    {
        Point position; // Counted from the top left
        Type radius = 0;
        Circle(Point pos, Type size) : position(pos), radius(size) {}
    };

    inline constexpr Type squareLengthInCircle(Type radius)
    {
        return radius * std::sqrt(2);
    }

    template<typename Shape>
    inline Shape& move(Shape& shape, Direction direction, SpeedType speed, TimeType deltaTime)
    {
        shape.position = shape.position + direction * speed * deltaTime;
        return shape;
    }

}


#endif //TOP_DOWN_SHOOTER_SHAPES_H
