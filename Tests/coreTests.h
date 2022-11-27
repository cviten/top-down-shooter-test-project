//
// Created by cviten on 11/12/22.
//

#ifndef TOP_DOWN_SHOOTER_CORETESTS_H
#define TOP_DOWN_SHOOTER_CORETESTS_H

#include "doctest.h"

#include "../Core/core.h"
#include "../Core/Shapes.h"

TEST_SUITE("Core")
{
    TEST_CASE("Distance")
    {
        Point zero, p1(0, 2), p2(3, 0), one(1, 1);
        CHECK_EQ(distance(zero, p1), doctest::Approx(2));
        CHECK_EQ(distance(zero, p2), doctest::Approx(3));
        CHECK_EQ(distance(zero, one), doctest::Approx(1.41).epsilon(0.1));
    }

    TEST_CASE("Normalization")
    {
        SUBCASE("v = 3z") {
            Vector vector(0, 3);
            CHECK_EQ(normalize(vector), Vector(0, 1));
        }
        SUBCASE("v = 2y") {
            Vector vector(2, 0);
            CHECK_EQ(normalize(vector), Vector(1, 0));
        }
        SUBCASE("v = x + y") {
            Vector vector(1, 1);
            CHECK_EQ(normalize(vector), Vector(0.709, 0.709));
        }
    }

    TEST_CASE("Vector Operators")
    {
        Point p1(1, 2), p2(2, 3);
        REQUIRE_EQ(p1, Point(1, 2));

        Vector v1(1, 2), v2(5, 3);
        REQUIRE_NE(v1, v2);

        CHECK_EQ(v1 + v2, Vector(6, 5));
        CHECK_EQ(v2 - v1, Vector(4, 1));
        CHECK_EQ(v1 - v2, Vector(-4, -1));
        CHECK_EQ(v1 * 3, Vector(3, 6));
        CHECK_EQ(5 * v1, Vector(5, 10));
//    CHECK_EQ(v1 * v2, 11);
    }

    TEST_CASE("Shapes - Rectangle")
    {
        using namespace Shapes;
        SUBCASE("Rectangle validation") {
            Rectangle rect({10, 20}, {10, 10}), invRect({}, {});
            REQUIRE(isRectangleValid(rect));
            REQUIRE_FALSE(isRectangleValid(invRect));
        }

        SUBCASE("Intersection 1 (Simple)") {
            Rectangle rect1({}, {30, 30}), rect2({}, {15, 15});
            const auto interRect = Rectangle::intersection(rect1, rect2);
            CHECK(isRectangleValid(interRect));
            CHECK_EQ(interRect.size, Size(15, 15));
        }
        SUBCASE("Intersection 2 (No intersection") {
            Rectangle rect1({}, {30, 30}), rect2({-15, -15}, {15, 15});
            const auto interRect = Rectangle::intersection(rect1, rect2);
            CHECK_FALSE(isRectangleValid(interRect));
        }

        SUBCASE("Intersection 3 (General)") {
            Rectangle rect1({10, 20}, {30, 30}), rect2({20, 10}, {15, 15});
            const auto interRect = Rectangle::intersection(rect1, rect2);
            CHECK(isRectangleValid(interRect));
            CHECK_EQ(interRect.position, Point(20, 20));
            CHECK_EQ(interRect.size, Size(15, 5));
        }

    }
}
#endif //TOP_DOWN_SHOOTER_CORETESTS_H
