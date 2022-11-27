//
// Created by cviten on 11/25/22.
//

#include "GameWorld.h"

GameWorld::GameWorld() : player(Shapes::Rectangle({0,0},{20,20})),
                         enemy(Shapes::Rectangle({100,0},{20,20})),
                         wall(Shapes::Rectangle({50,0},{20,20})) {}

std::vector<DrawObject> GameWorld::getDrawObjects() const {
    std::vector<DrawObject> pool;
    // Not optimal but easier on the eye
    pool.emplace_back(toDrawObject(player, DrawSettings::ObjectPaletteType::Player));
    pool.emplace_back(toDrawObject(enemy, DrawSettings::ObjectPaletteType::Enemy));
    pool.emplace_back(toDrawObject(wall, DrawSettings::ObjectPaletteType::Wall));
    return pool;
}

void GameWorld::process(TimeType deltaTime) {
    player.move({1, 0}, 400, deltaTime);
}
