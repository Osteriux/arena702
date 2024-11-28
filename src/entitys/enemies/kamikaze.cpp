#include "kamikaze.h"
#include "../../utils/manager/gameObjectManager.h"

Kamikaze::Kamikaze(float size, int health, float speed, int damage, Weapon* weapon, std::string texturePath, GameObjectManager *gameObjectManager, sf::Vector2f position, Score *score)
    : Enemy(size, health, weapon, speed, texturePath, gameObjectManager, position, score)
{
    this->damage = damage;
}

bool Kamikaze::update(float dt, sf::Vector2f playerPosition)
{
    this->orientate(playerPosition, dt);
    this->applyAcceleration();
    this->move(dt);
    this->iFrames(dt);
    return health <= 0;
}

void Kamikaze::onCollision(Entity *entity)
{
    if(typeid(*entity) == typeid(Player))
    {
        entity->takeDamage(this->damage);
        this->health = 0;
        this->onDeath();
    }
}

void Kamikaze::onDeath()
{
    this->gameObjectManager->addAnimation(std::make_unique<AnimationLine>("assets/boom.png", 11, sf::IntRect(0, 0, 250, 250), 0.1f, this->getPosition(), sf::Vector2f(0.6f, 0.6f)));
}