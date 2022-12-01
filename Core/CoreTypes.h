//
// Created by cviten on 11/14/22.
//

#ifndef TOP_DOWN_SHOOTER_CORETYPES_H
#define TOP_DOWN_SHOOTER_CORETYPES_H

// Consider to make into class (like Color)
enum class GameObjectType { Player, Enemy, Wall };

using IDType = int;

// using HPType = int
struct HPType {
    using Type = int;
    Type _HP;
    explicit HPType(Type hp) : _HP(hp) {}
    HPType operator+(HPType subHP) const { return HPType(_HP + subHP._HP);}
//    HPType operator+(Type subHP) const { return HPType(_HP + subHP);}
    HPType operator-(HPType subHP) const { Type resHP = _HP - subHP._HP; return HPType(resHP > 0 ? resHP : 0);}
//    HPType operator-(Type subHP) const { Type resHP = _HP - subHP._HP; return HPType(resHP > 0 ? resHP : 0);}
    HPType operator*(Type subHP) const { return HPType(_HP * subHP); }
};

using SpeedType = double;
using TimeType = double;

#endif //TOP_DOWN_SHOOTER_CORETYPES_H
