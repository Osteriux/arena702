#include "rocketShip.h"
#include "../../../utils/manager/gameObjectManager.h"

RocketShip::RocketShip(float size, int health, float speed, float cooldown, Weapon* weapon, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score)
    : Boss(size, health, weapon, speed, texturePath, gameObjectManager, position, score)
{
    this->cooldown = cooldown;
    currCooldown = 0.0f;
    angle = 0;
    radius = 300;
    sf::Vector2u arena = gameObjectManager->getArenaSize();
    center = sf::Vector2f(arena.x / 2, arena.y / 2);
}

void RocketShip::moveTarget(float dt)
{
    angle += 50.0f * dt;
    if (angle > 360){
        angle -= 360;
    }

    float radians = angle * M_PI / 180;
    float x = center.x + radius * cos(radians);
    float y = center.y + radius * sin(radians);
    target = sf::Vector2f(x, y);
}

void RocketShip::attack()
{
    gameObjectManager->spawnKamikaze(this->getPosition());
}

void RocketShip::attemptAttack(sf::Vector2f playerPosition)
{
    if (currCooldown <= 0)
    {
        this->attack();
        currCooldown = cooldown;
    }
}

bool RocketShip::update(float dt, sf::Vector2f playerPosition)
{
    this->moveTarget(dt);
    this->orientate(target, dt);
    this->applyAcceleration();
    this->move(dt);
    this->attemptAttack(playerPosition);
    currCooldown -= dt;
    if(currCooldown < 0){
        currCooldown = 0;
    }
    this->iFrames(dt);
    return health <= 0;
}
