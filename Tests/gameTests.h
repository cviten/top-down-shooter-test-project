//
// Created by cviten on 12/13/22.
//

#ifndef TOP_DOWN_SHOOTER_GAMETESTS_H
#define TOP_DOWN_SHOOTER_GAMETESTS_H

#include "doctest.h"

#include "Backend/GameLogic/GameObject.h"

TEST_SUITE("Game")
{
    TEST_CASE("Collision Body Creation")
    {
        SimpleGameObject<Shapes::Rectangle> rectBody(0, Shapes::Rectangle{{0,0},{10,10}}, GameObjectType::Debug);
        SimpleGameObject<Shapes::Circle> circleBody(0, Shapes::Circle{{0,0},10}, GameObjectType::Debug);
        CHECK_GT(rectBody.getCollisionBody().getShape().size.x, doctest::Approx(0));
        CHECK_GT(rectBody.getCollisionBody().getShape().size.y, doctest::Approx(0));
        CHECK_GT(circleBody.getCollisionBody().getShape().size.x, doctest::Approx(0));
        CHECK_GT(circleBody.getCollisionBody().getShape().size.y, doctest::Approx(0));
    }
}

#endif //TOP_DOWN_SHOOTER_GAMETESTS_H
