#pragma once
#include "boss.h"

class ShieldShip : public Boss
{
private:
    bool goalReached;
    void moveTarget(float dt) override{};
    void attemptAttack(sf::Vector2f playerPosition) override;
    void orientate(sf::Vector2f target, float dt) override;
    void bounceBack(Entity* entity) override{};
public:
    ShieldShip(float size, int health, float speed, Weapon* weapon, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score);
    void attack() override;
    void move(float dt) override;
    bool update(float dt, sf::Vector2f playerPosition) override;
    ~ShieldShip() = default;
};
