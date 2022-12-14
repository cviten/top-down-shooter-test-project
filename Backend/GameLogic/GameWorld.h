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
#include "Backend/GameLogic/GameObjects/GaneObjects.h"

class DrawObject;

class GameWorld {
    const Shapes::Rectangle defaultRect = Shapes::Rectangle({0,0}, {20,20});
    class IDTypeGen
    {
        IDType id = 0;
    public:
        IDType operator()() { return ++id;}
        IDType get() const { return id; }
    };

    Player player;

    // Look into making class that will be responsible for creation
    // Probably template since deletion is already templated
    MappingType<IDType, Bullet> bullets;
    MappingType<IDType, Wall> walls;
    MappingType<IDType, Enemy> enemies;

    void createBullet(Point startPosition, Direction direction, SpeedType speed);
    void createWall(Point position);
    void createEnemy(Point position);


    Direction playerDirection;
    Point targetPosition;
    bool shootCommand;

    Shapes::Rectangle playField;

    // Can be replaced with "erase_if" in C++20
    template <typename MapContainer>
    void deleteIfInactive(MapContainer& objContainer);

public:
    GameWorld();
    void process(TimeType deltaTime);
    std::vector<DrawObject> getDrawObjects() const;

    void setInputs(const Input::Inputs& inputs);

    void applyConfig(const Config& config);

    void setPlayField(const Size& screenSize);
};


#endif //TOP_DOWN_SHOOTER_GAMEWORLD_H
