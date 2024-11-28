#include "weaponFactory.h"

Weapon* WeaponFactory::createWeapon(WeaponType type, int damage, float cooldown, sf::Color color)
{
    switch (type)
    {
    case WeaponType::CLoseCombat:
        return new CloseCombat(damage, 0.1f, cooldown, color);
    case WeaponType::Projectile:
        return new Gun(damage, 600.0f, cooldown, color, 1);
    case WeaponType::Laser:
        return new LaserGun(damage, 50.0f, cooldown, color);
    default:
        return new CloseCombat(damage, 0.1f, cooldown, color);
    }
}