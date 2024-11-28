#include "attack.h"
#include "../../entitys/entity.h"

Attack::Attack(Entity* owner, float damage, float speed, float duration, sf::Color color)
    : owner(owner), damage(damage), speed(speed), duration(duration)
{
    this->setColor(color);
}

bool Attack::collidesWith(const sf::FloatRect &rectangle)
{
    return getGlobalBounds().intersects(rectangle);
}

bool Attack::update(float dt)
{
    if(!owner){
        return true;
    }else{
        if(owner->getHealth() <= 0){
            return true;
        }
    }
    duration -= dt;
    if (duration <= 0)
    {
        return true;
    }
    return false;
}