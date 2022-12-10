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
class SimpleGameObject {
    IDType ID;
    GameObjectType gameObjectType;
    VisualBody<VisualShape> visualBody;
    CollisionBody collisionBody;
public:
    SimpleGameObject(IDType ID, const VisualShape& shape, GameObjectType type) : ID(ID), visualBody(shape), collisionBody(shape),
                                                                      gameObjectType(type) {}

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

    void move(Direction direction, SpeedType speed, TimeType deltaTime) {
        visualBody.move(direction, speed, deltaTime);
        collisionBody.move(direction, speed, deltaTime);
    }

    IDType getID() const {
        return ID;
    }
};

class Bullet : public SimpleGameObject<Shapes::Circle>
{
    using SimpleGameObject::SimpleGameObject;
    Direction direction;
    SpeedType speed;

public:
    Bullet(IDType ID, const Shapes::Circle& shape, const Direction& direction, SpeedType speed, GameObjectType type)
            : SimpleGameObject(ID, shape, type), direction(direction), speed(speed) {}

    SpeedType getSpeed() const {
        return speed;
    }

    const Direction& getDirection() const {
        return direction;
    }
};

struct BulletSpawner
{
    inline static Type defaultDistance = 30.0;
    static Point getPosition(Point objectCenter, Direction direction, Type distance = defaultDistance)
    {
        return objectCenter + normalize(direction) * distance;
    }
};

class Enemy : public SimpleGameObject<Shapes::Rectangle>
{
    using SimpleGameObject::SimpleGameObject;
};

class Player : public SimpleGameObject<Shapes::Rectangle>
{
    using SimpleGameObject::SimpleGameObject;
public:
    Point getBulletPosition(Direction direction) {
        return BulletSpawner::getPosition(getCollisionBody().getCenter(), direction);
    }
};

class Wall : public SimpleGameObject<Shapes::Rectangle>
{
    using SimpleGameObject::SimpleGameObject;
};

#endif //TOP_DOWN_SHOOTER_GAMEOBJECT_H
