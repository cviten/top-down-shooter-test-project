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

GameWorld::GameWorld() : player(0,Shapes::Rectangle({0,0},{20,20}), GameObjectType::Player)
                         {
                             createBullet({0, 500}, {1, 0}, Bullet::defaultSpeed());
                             createWall({200, 100});
                             createWall({110, 370});
                             createWall({240, 190});
                             createWall({360, 230});
                             createEnemy({700, 170});
                             createEnemy({620, 250});
                             createEnemy({570, 570});
                             createEnemy({220, 220});
                             createEnemy({100, 340});
                         }

std::vector<DrawObject> GameWorld::getDrawObjects() const {
    std::vector<DrawObject> pool;
    addDrawObject(pool, player);
    addDrawObjects(pool, bullets);
    addDrawObjects(pool, walls);
    addDrawObjects(pool, enemies);
    return pool;
}


void GameWorld::process(TimeType deltaTime) {
    const SpeedType walkSteps = Player::defaultSpeed() / 20.0;

    player.move(playerDirection, Player::defaultSpeed(), deltaTime);

    if(shootCommand)
    {
        Direction bulletDirection = targetPosition - getPosition(player);
        createBullet(player.getBulletPosition(bulletDirection), bulletDirection, Bullet::defaultSpeed());
    }

    // General optimization idea:
    // Divide screen/field into parts (for example, 4) and check collision only with objects in relevant parts
    // Algorithm will still be O(n) and O(n^2) but at least we can somewhat reduce amount of comparisons
    // Research more efficient algorithms

    for (const auto& [id, wall] : walls) {
        // TODO: Add sliding along the wall
        if( CollisionBody::check(player.getCollisionBody(), wall.getCollisionBody()))
        {
            player.move(-playerDirection, Player::defaultSpeed(), deltaTime);
            while (!CollisionBody::check(player.getCollisionBody(), wall.getCollisionBody()))
            {
                player.move(playerDirection, walkSteps, deltaTime);
            }
            player.move(-playerDirection, walkSteps, deltaTime);
        }

    }

    for (auto& [idBullet, bullet]: bullets) {
        bullet.move(bullet.getDirection(), bullet.getSpeed(), deltaTime);

        for (auto& [idEnemy, enemy] : enemies) {
            if (CollisionBody::check(enemy.getCollisionBody(), bullet.getCollisionBody())) {
                enemy.setActive(false);
            }
        }

        for (const auto& [idWall, wall] : walls) {
            if (CollisionBody::check(wall.getCollisionBody(), bullet.getCollisionBody())) {
                bullet.setActive(false);
            }
        }

        if (!playField.contains(getPosition(bullet))) {
            bullet.setActive(false);
        }
    }

    deleteIfInactive(bullets);
    deleteIfInactive(enemies);
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
    static IDTypeGen bulletID;
    const IDType id = bulletID();
    bullets.insert(std::make_pair(id, Bullet{id,Shapes::Circle({startPosition}, {7}), normalize(direction), Bullet::defaultSpeed() ,GameObjectType::Bullet}));
}

void GameWorld::createWall(Point position) {
    static IDTypeGen wallsID;
    const IDType id = wallsID();
    auto wallShape = defaultRect;
    wallShape.position = position;
    walls.insert(std::make_pair(id, Wall(id, wallShape, GameObjectType::Wall)));
}

void GameWorld::createEnemy(Point position) {
    static IDTypeGen enemyID;
    const IDType id = enemyID();
    auto enemyShape = defaultRect;
    enemyShape.position = position;
    enemies.insert(std::make_pair(id, Enemy(id, enemyShape, GameObjectType::Enemy)));
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