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

    MappingType<IDType, Bullet> bullets;

    Direction playerDirection;
    Point targetPosition;
    bool shootCommand;

    void createBullet(Point startPosition, Direction direction, SpeedType speed);

    Shapes::Rectangle playField;

    // TODO: Should be replaced with singleton that gives new number every call
    IDType bulletID = 0;

public:
    GameWorld();
    void process(TimeType deltaTime);
    std::vector<DrawObject> getDrawObjects() const;

    void setInputs(const Input::Inputs& inputs);

    void applyConfig(const Config& config);

    void setPlayField(const Size& screenSize);
};


#endif //TOP_DOWN_SHOOTER_GAMEWORLD_H
