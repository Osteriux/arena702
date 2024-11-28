#pragma once
#include <SFML/Graphics.hpp>
#include "../entitys/entity.h"

class Item : public sf::Sprite
{
protected:
    sf::Texture texture;
    bool isPickedUp;
    float timeToLive;
public:
    Item(std::string texturePath, sf::Vector2f position, float timeToLive);
    virtual void onPickup(Entity* e) = 0;
    virtual bool update(float dt);
    ~Item() = default;
};
