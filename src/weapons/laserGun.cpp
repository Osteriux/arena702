#include "laserGun.h"

LaserGun::LaserGun(int damage, float duration, float cooldown, sf::Color color)
    : Weapon(damage, duration, cooldown, 1000, color)
{
    this->offset = 0;
}

void LaserGun::setOffset(float offset)
{
    this->offset = offset;
}

void LaserGun::resetCooldown()
{
    currCooldown = 0;
}

std::unique_ptr<Attack> LaserGun::attack(Entity* owner)
{
    if(currCooldown <= 0)
    {
        currCooldown = cooldown;
        return std::make_unique<Laser>(owner, damage, 10.0f, color, offset);
    }
    return nullptr;
}