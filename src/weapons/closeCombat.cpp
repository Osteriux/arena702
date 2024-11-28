#include "closeCombat.h"

CloseCombat::CloseCombat(int damage, float duration, float cooldown, sf::Color color)
    : Weapon(damage, duration, cooldown, 60, color)
{
}

std::unique_ptr<Attack> CloseCombat::attack(Entity* owner)
{
    if(currCooldown > 0)
    {
        return nullptr;
    }else{
        this->currCooldown = cooldown;
        return std::make_unique<Slash>(damage, duration, owner, color);
    }
}
