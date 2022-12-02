//
// Created by cviten on 11/25/22.
//

#ifndef TOP_DOWN_SHOOTER_DRAWOBJECT_H
#define TOP_DOWN_SHOOTER_DRAWOBJECT_H

#include "Core.h"
#include "Shapes.h"

#include <map>

namespace DrawSettings
{
    enum Shape { Rectangle, Circle };
    struct Color
    {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char transparent;

        constexpr explicit Color() : red(255),
                            green(255),
                            blue(255),
                            transparent(255) {}
        constexpr Color(unsigned char red, unsigned char green, unsigned char blue) : red(red), green(green), blue(blue),
                        transparent(255){}
        constexpr Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char transparent) : red(red),
                                                                                                           green(green),
                                                                                                           blue(blue),
                                                                                                           transparent(
                                                                                                                   transparent) {}
    };

    namespace Colors
    {
        constexpr static Color Red{255,0,0};
        constexpr static Color Green{0,255,0};
        constexpr static Color Blue{0,0,255};
        constexpr static Color Yellow{255,255,0};
        constexpr static Color White{255,255,255};
        constexpr static Color Black{0,0,0};
        constexpr static Color Transparent{0,0,0,0};
    }

    using ObjectColorPalette = std::map<GameObjectType, Color>;
}




struct DrawObject
{
    DrawSettings::Shape shape;
    Point position;
    Size size;
    GameObjectType objectType;
    bool isWireFrame = false;

    DrawObject(DrawSettings::Shape shape, const Point& position, const Size& size, const GameObjectType& objectType)
            : shape(shape), position(position), size(size), objectType(objectType) {}

    DrawObject(const Shapes::Rectangle& rect, const GameObjectType& objectType) : shape(DrawSettings::Rectangle), position(rect.position),
                                                                                  size(rect.size), objectType(objectType) {}

    DrawObject(const Shapes::Circle& circle, const GameObjectType& objectType) : shape(DrawSettings::Circle), position(circle.position),
                                                                                 size(circle.radius, 0), objectType(objectType) {}
};

#endif //TOP_DOWN_SHOOTER_DRAWOBJECT_H
