#ifndef TOP_DOWN_SHOOTER_CORE_H
#define TOP_DOWN_SHOOTER_CORE_H

#include <iosfwd>

//#ifdef SFML_ENABLE
//#include <SFML/System/Vector2.hpp>
//using Vector2d = sf::Vector2<double>;
//#endif

namespace
{
    using Type = double;
}

//#ifdef SFML_ENABLE
//    using Type2D = Vector2d;
//#else
constexpr double EPSILON = 0.01;


struct XY {
    Type x;
    Type y;

    XY(Type x, Type y) : x(x), y(y) {}
    XY() : XY(0,0) {}
};


enum class CoordQuad { NegXY, NegXPosY, NegYPosX, PosXY, Axis };

inline CoordQuad checkCoordQuad(const XY& xy)
{
    if (xy.x > 0 && xy.y > 0) return CoordQuad::PosXY;
    if (xy.x < 0 && xy.y < 0) return CoordQuad::NegXY;
    if (xy.x > 0 && xy.y < 0) return CoordQuad::NegYPosX;
    if (xy.x < 0 && xy.y > 0) return CoordQuad::NegXPosY;
    return CoordQuad::Axis;
}

using Type2D = XY;

std::ostream& operator<<(std::ostream& stream, const Type2D& xy);
//#endif

// Consider separating into different classes
using Point = Type2D;
using Vector = Type2D;
using Size = Type2D;

// Subclasses (probably won't be separate classes in case of creating classes for main classes)
using Direction = Vector;

bool operator==(const Type2D& p1, const Type2D& p2);
bool operator!=(const Type2D& p1, const Type2D& p2);
Type2D operator-(const Type2D& xy);

Vector operator+ (const Vector& v1, const Vector& v2);
Vector operator- (const Vector& v1, const Vector& v2);
Type operator* (const Vector& v1, const Vector& v2);
Vector operator* (const Type& scale, const Vector& vector);
Vector operator* (const Vector& vector, const Type& scale);

Type distance(const Point& p1, const Point& p2);
Type vectorLength(const Vector& v);
Vector normalize(const Vector& vector);


#endif //TOP_DOWN_SHOOTER_CORE_H
