#include "projectile.h"

Projectile::Projectile(Entity* owner, float damage, float speed, float duration, int pierce, sf::Color color) 
    : Attack(owner, damage, speed, duration, color)
{
    this->pierce = pierce;
    this->direction = owner->getDirection();

    this->texture.loadFromFile("assets/projectile.png");
    this->setTexture(texture, true);
    this->setOrigin(12, 7.5);
    this->setPosition(owner->getPosition());
    this->setRotation(owner->getRotation());
}

void Projectile::onCollision(Entity* entity) {
    if(pierce > 0){
        entity->takeDamage(damage);
        pierce--;
    }
}

bool Projectile::update(float dt) {
    this->move(direction * speed * dt);
    return pierce <= 0 || Attack::update(dt);
}