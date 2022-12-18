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
#include "Level.h"
#include "Backend/GameLogic/GameObjects/GaneObjects.h"

class DrawObject;

class GameWorld {
public:
    struct Status
    {
        bool playerActive;
        uint enemyCount;
        uint bulletCount;
        uint wallCount;
        Status& setPlayerActive(bool active) { playerActive = active; return *this; }
        Status& setEnemyCount(uint count) { enemyCount = count; return *this; }
        Status& setBulletCount(uint count) { bulletCount = count; return *this; }
        Status& setWallCount(uint count) { wallCount = count; return *this; }
    };
private:
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
    ObjectMap<Bullet> bullets;
    ObjectMap<Wall> walls;
    ObjectMap<Enemy> enemies;

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

    void setLevel(const Level& level);

    void setInputs(const Input::Inputs& inputs);

    void applyConfig(const Config& config);

    void setPlayField(const Size& screenSize);

    Status getStatus() const;

    void clearLevel();
};


#endif //TOP_DOWN_SHOOTER_GAMEWORLD_H
