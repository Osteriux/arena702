#include "gun.h"

Gun::Gun(int damage, float bulletSpeed, float cooldown, sf::Color color, int pierce)
    : Weapon(damage, bulletSpeed, cooldown, 1000, color)
{
    this->bulletSpeed = bulletSpeed;
    this->pierce = pierce;
}

std::unique_ptr<Attack> Gun::attack(Entity* owner)
{
    if(currCooldown <= 0)
    {
        currCooldown = cooldown;
        return std::make_unique<Projectile>(owner, damage, bulletSpeed, duration, pierce, color);
    }
    return nullptr;
}