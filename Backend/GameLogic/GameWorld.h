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
#include "Core/Config.h"
// GameLogic
#include "GameObject.h"

class DrawObject;

class GameWorld {
    Player player;
    Enemy enemy;
    Wall wall;

    std::vector<Bullet> bullets;

    Direction playerDirection;
    SpeedType playerSpeed;
    SpeedType bulletSpeed;

    void createBullet(Point startPosition, Direction direction, SpeedType speed);
public:
    GameWorld();
    void process(TimeType deltaTime);
    std::vector<DrawObject> getDrawObjects() const;

    void setInputs(const Input::Inputs& inputs);

    void applyConfig(const Config& config);
};


#endif //TOP_DOWN_SHOOTER_GAMEWORLD_H
