//
// Created by cviten on 11/25/22.
//

#ifndef TOP_DOWN_SHOOTER_GAMEWORLD_H
#define TOP_DOWN_SHOOTER_GAMEWORLD_H

#include <vector>
#include <functional>

// Core
#include "DrawObject.h"
// GameLogic
#include "GameObject.h"

class GameWorld {
    PlayerInst player;
    EnemyInst enemy;
    WallInst wall;
public:
    GameWorld();
    void process(TimeType deltaTime);
    std::vector<DrawObject> getDrawObjects() const;
};

template<typename Object>
DrawObject toDrawObject(const Object& obj, DrawSettings::ObjectPaletteType type)
{
    return {obj.getVisualBody().getShape(), type};
}


#endif //TOP_DOWN_SHOOTER_GAMEWORLD_H
