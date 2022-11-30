//
// Created by cviten on 11/25/22.
//

#include "GameWorld.h"
#include "CoreTypes.h"

template <typename KeyType, typename ValueType>
inline ValueType getValueOrDefault(const std::map<KeyType,ValueType>& map, const KeyType& key)
{
    auto it = map.find(key);
    if(it != map.end()) return it->second;
    return {};
}

GameWorld::GameWorld() : player(Shapes::Rectangle({0,0},{20,20})),
                         enemy(Shapes::Rectangle({100,0},{20,20})),
                         wall(Shapes::Rectangle({50,0},{20,20})) {}

std::vector<DrawObject> GameWorld::getDrawObjects() const {
    std::vector<DrawObject> pool;
    // Not optimal but easier on the eye
    pool.emplace_back(toDrawObject(player, GameObjectType::Player));
    pool.emplace_back(toDrawObject(enemy, GameObjectType::Enemy));
    pool.emplace_back(toDrawObject(wall, GameObjectType::Wall));
    return pool;
}

void GameWorld::process(TimeType deltaTime) {
    player.move(playerDirection, 400, deltaTime);

}

void GameWorld::setInputAction(const Input::InputActions& actions) {

}

void GameWorld::setInputAxes(const Input::InputAxes& axes) {
    playerDirection = getValueOrDefault(axes,Input::InputAxis::Move);
}
