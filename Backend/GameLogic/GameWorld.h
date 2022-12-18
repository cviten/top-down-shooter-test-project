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
#include "GameLog.h"

class DrawObject;

class GameWorld {
public:
    struct Status
    {
        using ObjectInfo = Point;
        using ObjectInfoVec = std::vector<ObjectInfo>;


        bool playerActive;
        ObjectInfo playerInfo;

        ObjectInfoVec enemiesInfo;
        ObjectInfoVec bulletsInfo;
        ObjectInfoVec wallsInfo;

        Status& setPlayerInfo(const Player& player) {
            playerInfo = player.getPosition();
            playerActive = player.isActive();
            return *this;
        }
        Status& setEnemyInfo(const ObjectMap<Enemy>& map) {
            for(const auto& [id,obj] : map)
                enemiesInfo.push_back(obj.getPosition());
            return *this;
        }
        Status& setBulletInfo(const ObjectMap<Bullet>& map) {
            for(const auto& [id,obj] : map)
                bulletsInfo.push_back(obj.getPosition());
            return *this;
        }
        Status& setWallInfo(const ObjectMap<Wall>& map) {
            for(const auto& [id,obj] : map)
                wallsInfo.push_back(obj.getPosition());
            return *this;
        }
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
    bool shootCommand = false;

    Shapes::Rectangle playField;

    GameLog gameLog;

    // Can be replaced with "erase_if" in C++20
    template <typename MapContainer>
    void deleteIfInactive(MapContainer& objContainer);

public:
    GameWorld();
    void process(TimeType deltaTime);
    std::vector<DrawObject> getDrawObjects() const;

    void setLevel(const Level& level);
    bool validateLevelStatus();

    void setInputs(const Input::Inputs& inputs);

    void applyConfig(const Config& config);

    void setPlayField(const Size& screenSize);

    Status getStatus() const;

    void clearLevel();
};


#endif //TOP_DOWN_SHOOTER_GAMEWORLD_H
