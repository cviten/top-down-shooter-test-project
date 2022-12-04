//
// Created by cviten on 11/14/22.
//

#ifndef TOP_DOWN_SHOOTER_GAMEOBJECT_H
#define TOP_DOWN_SHOOTER_GAMEOBJECT_H

#include "Core/Core.h"
#include "Core/CoreTypes.h"
#include "Bodies/CollisionBody.h"
#include "Bodies/VisualBody.h"

template<typename VisualShape>
class SimpleGameObject
{
    GameObjectType gameObjectType;
    VisualBody<VisualShape> visualBody;
    CollisionBody collisionBody;
public:
    SimpleGameObject(const VisualShape& shape, GameObjectType type) : visualBody(shape), collisionBody(shape), gameObjectType(type) {}
    void setActive(bool isActive) {
        visualBody.setActive(isActive);
        collisionBody.setActive(isActive);
    }

    GameObjectType getGameObjectType() const {
        return gameObjectType;
    }

    const VisualBody<VisualShape>& getVisualBody() const {
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

class Bullet : public SimpleGameObject<Shapes::Circle>
{
    using SimpleGameObject::SimpleGameObject;
    Direction direction;
    SpeedType speed;

public:
    Bullet(const Shapes::Circle& shape, const Direction& direction, SpeedType speed, GameObjectType type)
            : SimpleGameObject(shape, type), direction(direction), speed(speed) {}

    SpeedType getSpeed() const {
        return speed;
    }

    const Direction& getDirection() const {
        return direction;
    }
};

class Enemy : public SimpleGameObject<Shapes::Rectangle>
{
    using SimpleGameObject::SimpleGameObject;
};

class Player : public SimpleGameObject<Shapes::Rectangle>
{
    using SimpleGameObject::SimpleGameObject;
};

class Wall : public SimpleGameObject<Shapes::Rectangle>
{
    using SimpleGameObject::SimpleGameObject;
};

#endif //TOP_DOWN_SHOOTER_GAMEOBJECT_H
