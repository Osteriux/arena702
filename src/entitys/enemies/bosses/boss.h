#pragma once
#include "../enemy.h"

class Boss : public Enemy
{
protected:
    sf::Vector2f target;
    virtual void moveTarget(float dt) = 0;
    virtual void attemptAttack(sf::Vector2f playerPosition) override = 0;
public:
    Boss(float size, int health, Weapon* weapon, float speed, const std::string& texturePath, GameObjectManager* gameObjectManager, const sf::Vector2f& position, Score* score);
    virtual void attack() override = 0;
    virtual bool update(float dt, sf::Vector2f playerPosition) override = 0;
    ~Boss() = default;

};