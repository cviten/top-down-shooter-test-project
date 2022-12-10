//
// Created by cviten on 12/10/22.
//

#ifndef TOP_DOWN_SHOOTER_ENEMY_H
#define TOP_DOWN_SHOOTER_ENEMY_H

#include "Backend/GameLogic/GameObject.h"

class Enemy : public SimpleGameObject<Shapes::Rectangle>
{
    using SimpleGameObject::SimpleGameObject;
};

#endif //TOP_DOWN_SHOOTER_ENEMY_H
