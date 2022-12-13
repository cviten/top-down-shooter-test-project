//
// Created by cviten on 11/25/22.
//

#include "GameWorld.h"
#include "Core/CoreTypes.h"
#include "Core/DrawObject.h"
#include "Core/Util.h"

template <typename GameObject>
DrawObject toDrawObject(const GameObject& obj);

template <typename GameObject>
Point getPosition(const GameObject& obj);

template <typename GameObject>
void addDrawObject(std::vector<DrawObject>& pool, const GameObject& obj);

template <typename Container>
void addDrawObjects(std::vector<DrawObject>& pool, const Container& objContainer);

//Bullet createBullet(Point startPosition, Direction direction);
// =====================

GameWorld::GameWorld() : player(0,Shapes::Rectangle({0,0},{20,20}), GameObjectType::Player),
                         enemy(0,Shapes::Rectangle({100,200},{20,20}), GameObjectType::Enemy),
                         wall(0,Shapes::Rectangle({300,50},{20,20}), GameObjectType::Wall)
                         {
                             createBullet({0, 500}, {1, 0}, Bullet::defaultSpeed());
                         }

std::vector<DrawObject> GameWorld::getDrawObjects() const {
    std::vector<DrawObject> pool;
    addDrawObject(pool, player);
    addDrawObject(pool, wall);
    addDrawObject(pool, enemy);
    addDrawObjects(pool, bullets);
    return pool;
}


void GameWorld::process(TimeType deltaTime) {
    const SpeedType walkSteps = Player::defaultSpeed() / 20.0;

    auto& playerControlledObject = player;
    playerControlledObject.move(playerDirection, Player::defaultSpeed(), deltaTime);

    // TODO: Add sliding along the wall
    if( CollisionBody::check(playerControlledObject.getCollisionBody(), wall.getCollisionBody()))
    {
        playerControlledObject.move(-playerDirection, Player::defaultSpeed(), deltaTime);
        while (!CollisionBody::check(playerControlledObject.getCollisionBody(), wall.getCollisionBody()))
        {
            playerControlledObject.move(playerDirection, walkSteps, deltaTime);
        }
        playerControlledObject.move(-playerDirection, walkSteps, deltaTime);
    }

    if(shootCommand)
    {
        Direction bulletDirection = targetPosition - getPosition(player);
        createBullet(player.getBulletPosition(bulletDirection), bulletDirection, Bullet::defaultSpeed());
    }

    for (auto& [id,bullet] : bullets) {
        bullet.move(bullet.getDirection(),bullet.getSpeed(), deltaTime);
        if( CollisionBody::check(enemy.getCollisionBody(), bullet.getCollisionBody()))
        {
            enemy.setActive(false);
        }

        if( CollisionBody::check(wall.getCollisionBody(), bullet.getCollisionBody()))
        {
            bullet.setActive(false);
        }

        if(!playField.contains(getPosition(bullet)))
        {
            bullet.setActive(false);
        }
    }
    deleteIfInactive(bullets);
}

void GameWorld::applyConfig(const Config& config) {
    SpeedType playerSpeed = config.getAsSpeed("PlayerSpeed");
    SpeedType bulletSpeed = config.getAsSpeed("BulletSpeed");
    if (playerSpeed > EPSILON) Player::setDefaultSpeed(playerSpeed);
    if (bulletSpeed > EPSILON) Bullet::setDefaultSpeed(bulletSpeed);

}

void GameWorld::setInputs(const Input::Inputs& inputs) {
    playerDirection = getValueOrDefault(inputs.axes,Input::InputAxis::Move);
    targetPosition = getValueOrDefault(inputs.points,Input::InputPoint::TargetPosition);
    shootCommand = getValueOrDefault(inputs.actions,Input::InputAction::Shoot);
}

void GameWorld::createBullet(Point startPosition, Direction direction, SpeedType speed) {
    const IDType id = bulletID();
    bullets.insert(std::make_pair(id, Bullet{id,Shapes::Circle({startPosition}, {7}), normalize(direction), Bullet::defaultSpeed() ,GameObjectType::Bullet}));
}

void GameWorld::setPlayField(const Size& screenSize) {
    playField.position = {0 - screenSize.x * 0.5, 0 - screenSize.y * 0.5};
    playField.size = screenSize * 2;
}

template<typename MapContainer>
void GameWorld::deleteIfInactive(MapContainer& objContainer) {
    std::vector<IDType> objectIDToDelete;
    for (auto& [id,obj] : objContainer) {
        if(!obj.isActive())
        {
            objectIDToDelete.push_back(obj.getID());
        }
    }
    for (auto objID : objectIDToDelete) {
        objContainer.erase(objID);
    }
}
// =====================

template <typename GameObject>
DrawObject toDrawObject(const GameObject& obj)
{
    if (obj.getVisualBody().isActive()) {
        return {obj.getVisualBody().getShape(), obj.getGameObjectType()};
    }
}

template <typename GameObject>
Point getPosition(const GameObject& obj)
{
    return obj.getCollisionBody().getPosition();
}

template <typename GameObject>
void addDrawObject(std::vector<DrawObject>& pool, const GameObject& obj)
{
    if (obj.getVisualBody().isActive()) {
        pool.emplace(std::cend(pool), obj.getVisualBody().getShape(), obj.getGameObjectType());
    }
}

template <typename Container>
void addDrawObjects(std::vector<DrawObject>& pool, const Container& objContainer)
{
    for(const auto& [id,obj] : objContainer)
    {
        addDrawObject(pool,obj);
    }
}