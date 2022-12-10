//
// Created by cviten on 12/10/22.
//

#ifndef TOP_DOWN_SHOOTER_PLAYER_H
#define TOP_DOWN_SHOOTER_PLAYER_H

#include "Backend/GameLogic/GameObject.h"

class Player : public SimpleGameObject<Shapes::Rectangle>
{
    using SimpleGameObject::SimpleGameObject;
    inline static SpeedType _defaultSpeed = 300;
public:
    Point getBulletPosition(Direction direction) {
        return BulletSpawner::getPosition(getCollisionBody().getCenter(), direction);
    }

    static void setDefaultSpeed(SpeedType newSpeed) { _defaultSpeed = newSpeed; }
    static SpeedType defaultSpeed() { return _defaultSpeed; }
};

#endif //TOP_DOWN_SHOOTER_PLAYER_H
