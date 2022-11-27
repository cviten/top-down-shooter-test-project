//
// Created by cviten on 11/14/22.
//

#ifndef TOP_DOWN_SHOOTER_GAMEENTITES_H
#define TOP_DOWN_SHOOTER_GAMEENTITES_H

#include "CoreTypes.h"

struct Player
{
    HPType maxHP;
    SpeedType speed;
    IDType weaponID;
};

// Shouldn't be used for time
struct Weapon
{
    IDType weaponID;
    TimeType rateOfFire;
    IDType bulletID;
};

struct Bullet
{
    IDType weaponID;
    SpeedType speed;
    HPType damage;
    IDType bulletID;
};

struct Enemy
{
    IDType enemyID;
    HPType maxHP;
    SpeedType speed;
    IDType bulletID;
};

#endif //TOP_DOWN_SHOOTER_GAMEENTITES_H
