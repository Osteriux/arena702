#include "animation.h"

Animation::Animation(std::string texturePath, sf::IntRect rect, float switchTime, sf::Vector2f position, sf::Vector2f scale)
{
    texture.loadFromFile(texturePath);
    this->rect = rect;
    this->switchTime = switchTime;
    currentTime = 0.0f;
    setTexture(texture);
    setTextureRect(rect);
    setOrigin(rect.width / 2, rect.height / 2);
    setPosition(position);
    setScale(scale);
}

sf::Texture Animation::getTexture() const
{
    return texture;
}