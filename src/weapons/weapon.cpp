#include "weapon.h"

Weapon::Weapon(int damage, float duration, float cooldown, int range, sf::Color color)
{
    this->damage = damage;
    this->duration = duration;
    this->cooldown = cooldown;
    this->currCooldown = 0;
    this->range = range;
    this->color = color;
}

int Weapon::getRange() const
{
    return range;
}

void Weapon::setDamage(int damage)
{
    this->damage = damage;
}

bool Weapon::isReady() const
{
    return currCooldown <= 0;
}

void Weapon::update(float dt)
{
    if(currCooldown > 0)
    {
        currCooldown -= dt;
    }
}

void Weapon::reset()
{
    currCooldown = 0;
}