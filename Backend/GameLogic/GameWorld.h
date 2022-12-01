//
// Created by cviten on 11/25/22.
//

#ifndef TOP_DOWN_SHOOTER_GAMEWORLD_H
#define TOP_DOWN_SHOOTER_GAMEWORLD_H

#include <vector>
#include <functional>

// Core
#include "Core/Input.h"
#include "Core/CoreTypes.h"
// GameLogic
#include "GameObject.h"

class GameWorld {
    Player player;
    Enemy enemy;
    Wall wall;

    Direction playerDirection;
public:
    GameWorld();
    void process(TimeType deltaTime);
    std::vector<DrawObject> getDrawObjects() const;

    void setInputAction(const Input::InputActions& actions);
    void setInputAxes(const Input::InputAxes& axes);
};


#endif //TOP_DOWN_SHOOTER_GAMEWORLD_H
