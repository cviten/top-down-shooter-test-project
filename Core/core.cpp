#include "core.h"

#include <cmath>

#include <iostream>

Type distance(const Point &p1, const Point &p2) {
    return std::hypot(p2.x-p1.x, p2.y - p1.y);
}

std::ostream &operator<<(std::ostream &stream, const Type2D& xy) {
    stream << "(" << xy.x << ", " << xy.y << ")";
    return stream;
}

bool operator==(const XY &p1, const XY &p2) {
    return (std::abs(p1.x - p2.x) < EPSILON) && (std::abs(p1.y - p2.y) < EPSILON);
}

bool operator!=(const XY &p1, const XY &p2) {
    return !(p1 == p2);
}

Vector operator*(const Vector &vector, const Type &scale) {
    return {vector.x * scale, vector.y * scale};
}

Vector operator*(const Type &scale, const Vector &vector) {
    return {vector.x * scale, vector.y * scale};
}

Type operator*(const Vector &v1, const Vector &v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

Vector operator-(const Vector &v1, const Vector &v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

Vector operator+(const Vector &v1, const Vector &v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}

Type2D operator-(const Type2D& xy)
{
    return {-xy.x, -xy.y};
}

Point move(const Point &point, const Vector &vector) {
    return {point.x + vector.x, point.y + vector.y};
}

Vector normalize(const Vector &vector) {
    const auto length = vectorLength(vector);
    if (length < EPSILON) return {};
    return {vector.x / length, vector.y / length};
}

Type vectorLength(const Vector& v) {
    return distance(Point(), v);
}
