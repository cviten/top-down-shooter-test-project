//
// Created by cviten on 11/14/22.
//

#ifndef TOP_DOWN_SHOOTER_CORETYPES_H
#define TOP_DOWN_SHOOTER_CORETYPES_H

#include <unordered_map>

// Consider to make into class (like Color)
enum class GameObjectType { Player, Enemy, Wall, Bullet };

template<typename KeyType, typename ValueType>
using MappingType = std::unordered_map<KeyType,ValueType>;

// Consider moving it to the Core/GameTypes.h
using SpeedType = double;
using TimeType = double;

#endif //TOP_DOWN_SHOOTER_CORETYPES_H
