#pragma once
#include "boss.h"

class RocketShip : public Boss
{
private:
    float cooldown;
    float currCooldown;
    float angle;
    float radius;
    sf::Vector2f center;
    void moveTarget(float dt) override;
    void attemptAttack(sf::Vector2f playerPosition) override;
public:
    RocketShip(float size, int health, float speed, float cooldown, Weapon* weapon, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score);
    void attack() override;
    bool update(float dt, sf::Vector2f playerPosition) override;
    ~RocketShip() = default;
};