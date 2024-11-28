#include "healBall.h"

HealBall::HealBall(std::string texturePath, sf::Vector2f position, float timeToLive)
    : Item(texturePath, position, timeToLive)
    , elapsedTime(0.0f), bobbingSpeed(2.0f), bobbingHeight(10.0f)
{
    initialPosition = getPosition();
}

void HealBall::onPickup(Entity* e)
{
    if(!isPickedUp){
        e->heal(10);
        isPickedUp = true;
    }
}

bool HealBall::update(float dt)
{
    elapsedTime += dt;
    float offsetY = std::sin(elapsedTime * bobbingSpeed) * bobbingHeight;
    setPosition(initialPosition.x, initialPosition.y + offsetY);
    return Item::update(dt);
}