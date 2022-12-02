//
// Created by cviten on 11/25/22.
//

#include "GameWorld.h"
#include "Core/CoreTypes.h"
#include "Core/DrawObject.h"
#include "Core/Util.h"

template <typename GameObject>
DrawObject toDrawObject(const GameObject& obj)
{
    if (obj.getVisualBody().isActive()) {
        return {obj.getVisualBody().getShape(), obj.getGameObjectType()};
    }
    else
    {
        return {Shapes::Circle({}, {}), obj.getGameObjectType()};
    }
}

GameWorld::GameWorld() : player(Shapes::Rectangle({0,0},{20,20}), GameObjectType::Player),
                         enemy(Shapes::Rectangle({100,200},{20,20}), GameObjectType::Enemy),
                         wall(Shapes::Rectangle({300,50},{20,20}), GameObjectType::Wall),
                         bullet(Shapes::Circle({400,400}, {7}), GameObjectType::Bullet){}

std::vector<DrawObject> GameWorld::getDrawObjects() const {
    std::vector<DrawObject> pool;
    // Not optimal but easier on the eye
    pool.emplace_back(toDrawObject(player));
    pool.emplace_back(toDrawObject(enemy));
    pool.emplace_back(toDrawObject(wall));
    pool.emplace_back(toDrawObject(bullet));
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

    if( CollisionBody::check(playerControlledObject.getCollisionBody(), bullet.getCollisionBody()))
    {
        playerControlledObject.setActive(false);
    }

}

void GameWorld::setInputAction(const Input::InputActions& actions) {

}

void GameWorld::setInputAxes(const Input::InputAxes& axes) {
    playerDirection = getValueOrDefault(axes,Input::InputAxis::Move);
}

void GameWorld::applyConfig(const Config& config) {
    playerSpeed = config.getAsSpeed("PlayerSpeed");
}
