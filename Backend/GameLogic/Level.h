//
// Created by cviten on 12/14/22.
//

#ifndef TOP_DOWN_SHOOTER_LEVEL_H
#define TOP_DOWN_SHOOTER_LEVEL_H

#include <vector>
#include "Core/Core.h"

struct Level
{
    struct BulletSpawn
    {
        Point position;
        Direction direction;

        BulletSpawn(const Point& position, const Direction& direction) : position(position), direction(direction) {}
    };
    Point playerPosition;
    std::vector<Point> wallPosition;
    std::vector<Point> enemyPosition;
    std::vector<BulletSpawn> bulletSpawns;
    Level& addWalls(const std::vector<Point>& points) {
        for (const auto& point : points) {
            wallPosition.push_back(point);
        }
        return *this;
    }
    Level& addEnemies(const std::vector<Point>& points) {
        for (const auto& point : points) {
            enemyPosition.push_back(point);
        }
        return *this;
    }
    Level& addBullets(const std::vector<BulletSpawn>& bullets) {
        for (const auto& bullet : bullets) {
            bulletSpawns.push_back(bullet);
        }
        return *this;
    }

};

#endif //TOP_DOWN_SHOOTER_LEVEL_H
