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

    bool isActive() const { return visualBody.isActive() || collisionBody.isActive(); }

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

struct BulletSpawner
{
    inline static Type defaultDistance = 30.0;
    static Point getPosition(Point objectCenter, Direction direction, Type distance = defaultDistance)
    {
        return objectCenter + normalize(direction) * distance;
    }
};

#endif //TOP_DOWN_SHOOTER_GAMEOBJECT_H
