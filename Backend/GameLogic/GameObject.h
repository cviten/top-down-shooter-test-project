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
    GameObjectType gameObjectType;
    VisualBody visualBody;
    CollisionBody collisionBody;
public:
    SimpleGameObject(const Shapes::Rectangle& rect, GameObjectType type) : visualBody(rect), collisionBody(rect), gameObjectType(type) {}
    void setActive(bool isActive) {
        visualBody.setActive(isActive);
        collisionBody.setActive(isActive);
    }

    GameObjectType getGameObjectType() const {
        return gameObjectType;
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

class Bullet : public SimpleGameObject
{
    using SimpleGameObject::SimpleGameObject;
};

class Enemy : public SimpleGameObject
{
    using SimpleGameObject::SimpleGameObject;
};

class Player : public SimpleGameObject
{
    using SimpleGameObject::SimpleGameObject;
};

class Wall : public SimpleGameObject
{
    using SimpleGameObject::SimpleGameObject;
};

#endif //TOP_DOWN_SHOOTER_GAMEOBJECT_H
