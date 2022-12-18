//
// Created by cviten on 12/13/22.
//

#ifndef TOP_DOWN_SHOOTER_GAMETESTS_H
#define TOP_DOWN_SHOOTER_GAMETESTS_H

#include "doctest.h"

#include "Backend/GameLogic/GameObject.h"
#include "Backend/GameLogic/GameWorld.h"

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
    TEST_CASE("Game world")
    {
        GameWorld gameWorld;
        gameWorld.setPlayField({1000, 1000});

        SUBCASE("Level loading") {
            SUBCASE("Standard") {
                Level level;

                level.enemyPosition.emplace_back(620, 250);
                level.enemyPosition.emplace_back(570, 570);
                level.enemyPosition.emplace_back(220, 220);
                level.enemyPosition.emplace_back(100, 340);

                level.wallPosition.emplace_back(200, 100);
                level.wallPosition.emplace_back(200, 100);
                level.wallPosition.emplace_back(110, 370);
                level.wallPosition.emplace_back(240, 190);
                level.wallPosition.emplace_back(360, 230);
                level.wallPosition.emplace_back(700, 170);

                level.bulletSpawns.push_back(Level::BulletSpawn({0, 500}, {1, 0}));



                gameWorld.setLevel(level);

                CHECK(gameWorld.validateLevelStatus());

                gameWorld.process(0);

                REQUIRE_EQ(gameWorld.getStatus().enemiesInfo.size(), 4);
                REQUIRE_EQ(gameWorld.getStatus().wallsInfo.size(), 6);
                REQUIRE_EQ(gameWorld.getStatus().bulletsInfo.size(), 1);

            }
            SUBCASE("Invalid (Player over Walls)")
            {
                Level level;

                level.playerPosition = {620, 250};
                level.wallPosition.emplace_back(620, 250);

                gameWorld.setLevel(level);
                CHECK_FALSE(gameWorld.validateLevelStatus());
            }
        }
        SUBCASE("Collisions") {
            SUBCASE("Bullets and Enemies") {
                Level level;

                level.enemyPosition.emplace_back(620, 250);
                level.enemyPosition.emplace_back(570, 570);
                level.enemyPosition.emplace_back(220, 220);
                level.enemyPosition.emplace_back(100, 340);

                level.bulletSpawns.push_back(Level::BulletSpawn({620, 250}, {1, 0}));
                level.bulletSpawns.push_back(Level::BulletSpawn({570, 570}, {1, 0}));
                level.bulletSpawns.push_back(Level::BulletSpawn({220, 220}, {1, 0}));
                level.bulletSpawns.push_back(Level::BulletSpawn({100, 340}, {1, 0}));

                gameWorld.setLevel(level);
                gameWorld.process(0);

                CHECK(gameWorld.validateLevelStatus());

                CHECK_EQ(gameWorld.getStatus().enemiesInfo.size(), 0);
                CHECK_EQ(gameWorld.getStatus().bulletsInfo.size(), 4);
            }

            SUBCASE("Bullets and Walls") {
                Level level;

                level.wallPosition.emplace_back(620, 250);
                level.wallPosition.emplace_back(570, 570);
                level.wallPosition.emplace_back(220, 220);
                level.wallPosition.emplace_back(100, 340);

                level.bulletSpawns.push_back(Level::BulletSpawn({620, 250}, {1, 0}));
                level.bulletSpawns.push_back(Level::BulletSpawn({570, 570}, {1, 0}));
                level.bulletSpawns.push_back(Level::BulletSpawn({220, 220}, {1, 0}));
                level.bulletSpawns.push_back(Level::BulletSpawn({100, 340}, {1, 0}));

                gameWorld.setLevel(level);
                gameWorld.process(0.0);

                CHECK(gameWorld.validateLevelStatus());

                CHECK_EQ(gameWorld.getStatus().bulletsInfo.size(), 0);
                CHECK_EQ(gameWorld.getStatus().wallsInfo.size(), 4);
            }
        }

    }
}

#endif //TOP_DOWN_SHOOTER_GAMETESTS_H
