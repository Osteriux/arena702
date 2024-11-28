#pragma once
#include "../item.h"
#include <cmath>
#include <SFML/Graphics.hpp>

class HealBall : public Item
{
private:
    float elapsedTime;
    float bobbingSpeed;
    float bobbingHeight;
    sf::Vector2f initialPosition;
public:
    HealBall(std::string texturePath, sf::Vector2f position, float timeToLive);
    void onPickup(Entity* e) override;
    bool update(float dt) override;
};
