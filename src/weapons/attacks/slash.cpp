#include "slash.h"
#include <iostream>

Slash::Slash(int damage, float duration, Entity* owner, sf::Color color)
    : Attack(owner, damage, 0, duration, color)
{
    this->texture.loadFromFile("assets/slash.png");
    this->setTexture(this->texture, true);
    this->setScale(2, 2);
    this->setPosition(owner->getPosition());
    this->setOrigin(0, 12);
    this->setRotation(owner->getRotation());
}

void Slash::onCollision(Entity* entity)
{
    entity->takeDamage(damage);
}

bool Slash::update(float dt)
{
    if(owner){
        this->setPosition(owner->getPosition());
        this->setRotation(owner->getRotation());
    }
    return Attack::update(dt);
}