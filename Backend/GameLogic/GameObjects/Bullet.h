//
// Created by cviten on 12/10/22.
//

#ifndef TOP_DOWN_SHOOTER_BULLET_H
#define TOP_DOWN_SHOOTER_BULLET_H

#include "Backend/GameLogic/GameObject.h"

class Bullet : public SimpleGameObject<Shapes::Circle>
{
    using SimpleGameObject::SimpleGameObject;
    Direction direction;
    SpeedType speed;

    inline static SpeedType _defaultSpeed = 500;

public:
    Bullet(IDType ID, const Shapes::Circle& shape, const Direction& direction, SpeedType speed, GameObjectType type)
            : SimpleGameObject(ID, shape, type), direction(direction), speed(speed) {}

    SpeedType getSpeed() const {
        return speed;
    }

    const Direction& getDirection() const {
        return direction;
    }

    static void setDefaultSpeed(SpeedType newSpeed) { _defaultSpeed = newSpeed; }
    static SpeedType defaultSpeed() { return _defaultSpeed; }
};

#endif //TOP_DOWN_SHOOTER_BULLET_H
