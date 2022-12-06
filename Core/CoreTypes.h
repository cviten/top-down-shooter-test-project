//
// Created by cviten on 11/14/22.
//

#ifndef TOP_DOWN_SHOOTER_CORETYPES_H
#define TOP_DOWN_SHOOTER_CORETYPES_H

#include <unordered_map>

// Consider to make into class (like Color)
enum class GameObjectType { Player, Enemy, Wall, Bullet };

// Currently we don't really care about overflow since no object of the same type will live long enough for getting
// the same id because of the overflow
using IDType = unsigned int;

template<typename KeyType, typename ValueType>
using MappingType = std::unordered_map<KeyType,ValueType>;

// Consider moving it to the Core/GameTypes.h
using SpeedType = double;
using TimeType = double;

#endif //TOP_DOWN_SHOOTER_CORETYPES_H
