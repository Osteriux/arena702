#include "shieldShip.h"
#include "../../../utils/manager/gameObjectManager.h"

ShieldShip::ShieldShip(float size, int health, float speed, Weapon* weapon, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score)
    : Boss(size, health, weapon, speed, texturePath, gameObjectManager, position, score)
{
    sf::Vector2u arena = gameObjectManager->getArenaSize();
    target = sf::Vector2f(arena.x / 2, arena.y / 2);
    this->iFrameColor = sf::Color(127, 255, 127, 200);
    this->rotationSpeed = 90;
    this->goalReached = false;
    this->bounceFactor = 0.0f;  
}

void ShieldShip::attack()
{
    this->gameObjectManager->addEnemyAttack(this->weapon->attack(this));
}

void ShieldShip::orientate(sf::Vector2f target, float dt)
{
    sf::Vector2f direction = target - this->getPosition();
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if(goalReached)
    {
        // turn arround rotation
        this->rotate(rotationSpeed * dt);
    }else{
        Entity::orientate(target, dt);
    }
}

void ShieldShip::move(float dt)
{
    if(!goalReached)
    {
        Enemy::move(dt);
    }
}

void ShieldShip::attemptAttack(sf::Vector2f playerPosition)
{
    if(weapon->isReady() && goalReached){
        weapon->setOffset(15.0f);
        attack();
        weapon->setOffset(-15.0f);
        weapon->resetCooldown();
        attack();
    }
}

bool ShieldShip::update(float dt, sf::Vector2f playerPosition)
{
    
    sf::Vector2f direction = target - this->getPosition();
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    if(distance < 1.0f)
    {
        goalReached = true;
    }else{
        // boss can't be hit while moving
        currIframes = iframes;
        goalReached = false;
    }
    this->orientate(target, dt);
    this->applyAcceleration();
    this->move(dt);
    this->attemptAttack(playerPosition);
    weapon->update(dt);
    this->iFrames(dt);
    return health <= 0;
}