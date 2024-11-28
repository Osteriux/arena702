#include "elite.h"
#include "../../utils/manager/gameObjectManager.h"

Elite::Elite(float size, int health, Weapon* weapon, float speed, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score)
    : Enemy(size, health, weapon, speed, texturePath, gameObjectManager, position, score)
{
}

void Elite::takeDamage(int damage)
{
    Enemy::takeDamage(damage);
}

void Elite::onDeath()
{
    Enemy::onDeath();
    score->addScore(100);
    gameObjectManager->spawnKamikaze(this->getPosition());
}