#include "boss.h"

Boss::Boss(float size, int health, Weapon* weapon, float speed, const std::string& texturePath, GameObjectManager* gameObjectManager, const sf::Vector2f& position, Score* score)
    : Enemy(size, health, weapon, speed, texturePath, gameObjectManager, position, score)
{
}