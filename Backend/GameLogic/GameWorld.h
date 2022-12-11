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
    class IDTypeGen
    {
        IDType id = 0;
    public:
        IDType operator()() { return ++id;}
        IDType get() const { return id; }
    };
    Player player;
    Enemy enemy;
    Wall wall;

    MappingType<IDType, Bullet> bullets;

    Direction playerDirection;
    Point targetPosition;
    bool shootCommand;

    void createBullet(Point startPosition, Direction direction, SpeedType speed);

    Shapes::Rectangle playField;

    // Can be replaced with "erase_if" in C++20
    template <typename MapContainer>
    void deleteIfInactive(MapContainer& objContainer);

    IDTypeGen bulletID;

public:
    GameWorld();
    void process(TimeType deltaTime);
    std::vector<DrawObject> getDrawObjects() const;

    void setInputs(const Input::Inputs& inputs);

    void applyConfig(const Config& config);

    void setPlayField(const Size& screenSize);
};


#endif //TOP_DOWN_SHOOTER_GAMEWORLD_H
