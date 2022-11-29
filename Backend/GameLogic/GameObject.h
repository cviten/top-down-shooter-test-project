//
// Created by cviten on 11/14/22.
//

#ifndef TOP_DOWN_SHOOTER_GAMEOBJECT_H
#define TOP_DOWN_SHOOTER_GAMEOBJECT_H

#include "Core/core.h"
#include "Core/CoreTypes.h"
#include "Bodies/CollisionBody.h"
#include "Bodies/VisualBody.h"

class SimpleGameObject
{
    VisualBody visualBody;
    CollisionBody collisionBody;
public:
    SimpleGameObject(const Shapes::Rectangle& rect) : visualBody(rect), collisionBody(rect) {}
    void setActive(bool isActive) {
        visualBody.setActive(isActive);
        collisionBody.setActive(isActive);
    }

    const VisualBody& getVisualBody() const {
        return visualBody;
    }

    const CollisionBody& getCollisionBody() const {
        return collisionBody;
    }

    void move(Direction direction, SpeedType speed, TimeType deltaTime)
    {
        visualBody.move(direction, speed, deltaTime);
        collisionBody.move(direction, speed, deltaTime);
    }
};

class BulletInst : public SimpleGameObject
{
    IDType bulletID;
};

class EnemyInst : public SimpleGameObject
{

//    IDType enemyID;
//    HPType currentHP;
    using SimpleGameObject::SimpleGameObject;
};

class PlayerInst : public SimpleGameObject
{
    using SimpleGameObject::SimpleGameObject;
//    HPType currentHP;
//    IDType currentWeaponID;
};

class WallInst : public SimpleGameObject
{
    using SimpleGameObject::SimpleGameObject;
//    HPType currentHP;
//    IDType currentWeaponID;
};

#endif //TOP_DOWN_SHOOTER_GAMEOBJECT_H
