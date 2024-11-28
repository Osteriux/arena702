#pragma once
#include "weapon.h"
#include "attacks/laser.h"

class LaserGun : public Weapon
{
private:
    float offset;
    int nbRay;
public:
    LaserGun(int damage, float duration, float cooldown, sf::Color color);
    void setOffset(float offset) override;
    void resetCooldown() override;
    std::unique_ptr<Attack> attack(Entity* owner) override;
    ~LaserGun() = default;
};
