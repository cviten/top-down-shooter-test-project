//
// Created by cviten on 12/10/22.
//

#ifndef TOP_DOWN_SHOOTER_WALL_H
#define TOP_DOWN_SHOOTER_WALL_H

#include "Backend/GameLogic/GameObject.h"

class Wall : public SimpleGameObject<Shapes::Rectangle>
{
    using SimpleGameObject::SimpleGameObject;
};

#endif //TOP_DOWN_SHOOTER_WALL_H
