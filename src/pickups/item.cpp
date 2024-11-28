#include "item.h"

Item::Item(std::string texturePath, sf::Vector2f position, float timeToLive)
{
    this->timeToLive = timeToLive;
    this->setPosition(position);
    this->texture.loadFromFile(texturePath);
    this->setTexture(this->texture, true);
    this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
    isPickedUp = false;
}

bool Item::update(float dt)
{
    if(isPickedUp)
    {
        return true;
    }
    timeToLive -= dt;
    if (timeToLive <= 0)
    {
        return true;
    }
    return false;
}