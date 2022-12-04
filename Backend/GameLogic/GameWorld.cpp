//
// Created by cviten on 11/25/22.
//

#include "GameWorld.h"
#include "Core/CoreTypes.h"
#include "Core/DrawObject.h"
#include "Core/Util.h"

template <typename GameObject>
DrawObject toDrawObject(const GameObject& obj);

template <typename GameObject>
void addDrawObject(std::vector<DrawObject>& pool, const GameObject& obj);

template <typename Container>
void addDrawObjects(std::vector<DrawObject>& pool, const Container& objContainer);

Bullet createBullet(Point startPosition, Direction direction);

// =====================

GameWorld::GameWorld() : player(Shapes::Rectangle({0,0},{20,20}), GameObjectType::Player),
                         enemy(Shapes::Rectangle({100,200},{20,20}), GameObjectType::Enemy),
                         wall(Shapes::Rectangle({300,50},{20,20}), GameObjectType::Wall)
                         {
                             bullets.reserve(20);
                             createBullet({0,500}, {0,-1}, 500);
                         }

std::vector<DrawObject> GameWorld::getDrawObjects() const {
    std::vector<DrawObject> pool;
    addDrawObject(pool, player);
    addDrawObject(pool, wall);
    addDrawObject(pool, enemy);
    addDrawObjects(pool, bullets);
    return pool;
}


void GameWorld::process(TimeType deltaTime) {
    const SpeedType walkSteps = playerSpeed / 20.0;

    auto& playerControlledObject = player;
    playerControlledObject.move(playerDirection, playerSpeed, deltaTime);

    // TODO: Add sliding along the wall
    if( CollisionBody::check(playerControlledObject.getCollisionBody(), wall.getCollisionBody()))
    {
        playerControlledObject.move(-playerDirection, playerSpeed, deltaTime);
        while (!CollisionBody::check(playerControlledObject.getCollisionBody(), wall.getCollisionBody()))
        {
            playerControlledObject.move(playerDirection, walkSteps, deltaTime);
        }
        playerControlledObject.move(-playerDirection, walkSteps, deltaTime);
    }

    for (auto& bullet : bullets) {
        bullet.move(bullet.getDirection(),bullet.getSpeed(), deltaTime);
        if( CollisionBody::check(playerControlledObject.getCollisionBody(), bullet.getCollisionBody()))
        {
            playerControlledObject.setActive(false);
        }
    }
}

void GameWorld::applyConfig(const Config& config) {
    playerSpeed = config.getAsSpeed("PlayerSpeed");
    bulletSpeed = config.getAsSpeed("BulletSpeed");
}

void GameWorld::setInputs(const Input::Inputs& inputs) {
    playerDirection = getValueOrDefault(inputs.axes,Input::InputAxis::Move);
}

void GameWorld::createBullet(Point startPosition, Direction direction, SpeedType speed) {
    bullets.emplace_back(Shapes::Circle({startPosition}, {7}), direction, speed ,GameObjectType::Bullet);
}

// =====================

template <typename GameObject>
DrawObject toDrawObject(const GameObject& obj)
{
    if (obj.getVisualBody().isActive()) {
        return {obj.getVisualBody().getShape(), obj.getGameObjectType()};
    }
}

template <typename GameObject>
void addDrawObject(std::vector<DrawObject>& pool, const GameObject& obj)
{
    if (obj.getVisualBody().isActive()) {
        pool.emplace(std::cend(pool), obj.getVisualBody().getShape(), obj.getGameObjectType());
    }
}

template <typename Container>
void addDrawObjects(std::vector<DrawObject>& pool, const Container& objContainer)
{
    for(const auto& obj : objContainer)
    {
        addDrawObject(pool,obj);
    }
}

Bullet createBullet(Point startPosition, Direction direction)
{
    return Bullet(Shapes::Circle({startPosition}, {7}),GameObjectType::Bullet);
}