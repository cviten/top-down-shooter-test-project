//
// Created by cviten on 11/25/22.
//

#include "GameWorld.h"
#include "Core/CoreTypes.h"
#include "Core/DrawObject.h"

template <typename KeyType, typename ValueType>
inline ValueType getValueOrDefault(const std::map<KeyType,ValueType>& map, const KeyType& key)
{
    auto it = map.find(key);
    if(it != map.end()) return it->second;
    return {};
}

template <typename GameObject>
DrawObject toDrawObject(const GameObject& obj)
{
    return {obj.getVisualBody().getShape(), obj.getGameObjectType()};
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
    // TODO: Replace with speed from player object or config
    const SpeedType playerSpeed = 400;
    const SpeedType walkSteps = playerSpeed / 20.0;
    player.move(playerDirection, playerSpeed, deltaTime);

    // TODO: Add sliding along the wall
    if( CollisionBody::check(player.getCollisionBody(), wall.getCollisionBody()))
    {
        player.move(-playerDirection, playerSpeed, deltaTime);
        while (!CollisionBody::check(player.getCollisionBody(), wall.getCollisionBody()))
        {
            player.move(playerDirection, walkSteps, deltaTime);
        }
        player.move(-playerDirection, walkSteps, deltaTime);
    }

}

void GameWorld::setInputAction(const Input::InputActions& actions) {

}

void GameWorld::setInputAxes(const Input::InputAxes& axes) {
    playerDirection = getValueOrDefault(axes,Input::InputAxis::Move);
}
