#include "laser.h"

Laser::Laser(Entity* owner, float damage, float duration, sf::Color color, float offset)
    : Attack(owner, damage, 0.0f, duration, color)
{
    this->offset = offset;
    this->distance = 1000.0f;

    setPosition(owner->getPosition());
    sf::Vector2f direction = owner->getDirection();
    setRotation((atan2(direction.y, direction.x) * 180 / M_PI) + offset);
    texture.loadFromFile("assets/laser.png");
    texture.setRepeated(true);
    setTexture(texture, true);
    setColor(sf::Color(255, 255, 255, 127));
    setOrigin(0, getLocalBounds().height / 2);
    setScale(10, 1);
}

bool Laser::collidesWith(const sf::FloatRect& rectangle)
{
    sf::Vector2f start = getPosition();
    sf::Vector2f end = start + sf::Vector2f(std::cos(getRotation() * M_PI / 180.0f) * distance, std::sin(getRotation() * M_PI / 180.0f) * distance);
    return lineIntersectsRect(start, end, rectangle);
}

void Laser::onCollision(Entity* entity)
{
    entity->takeDamage(damage);
}

bool Laser::update(float dt)
{
    if(owner){
        setPosition(owner->getPosition());
        setRotation(owner->getRotation() + offset);
    }
    return Attack::update(dt);
}

bool Laser::lineIntersectsRect(sf::Vector2f start, sf::Vector2f end, sf::FloatRect rect) const
{
    sf::Vector2f topLeft(rect.left, rect.top);
    sf::Vector2f topRight(rect.left + rect.width, rect.top);
    sf::Vector2f bottomLeft(rect.left, rect.top + rect.height);
    sf::Vector2f bottomRight(rect.left + rect.width, rect.top + rect.height);

    return (lineIntersectsLine(start, end, topLeft, topRight) ||
            lineIntersectsLine(start, end, topRight, bottomRight) ||
            lineIntersectsLine(start, end, bottomRight, bottomLeft) ||
            lineIntersectsLine(start, end, bottomLeft, topLeft));
}

bool Laser::lineIntersectsLine(sf::Vector2f s1, sf::Vector2f e1, sf::Vector2f s2, sf::Vector2f e2) const
{
    float s1_x = e1.x - s1.x;
    float s1_y = e1.y - s1.y;
    float s2_x = e2.x - s2.x;
    float s2_y = e2.y - s2.y;

    float s = (-s1_y * (s1.x - s2.x) + s1_x * (s1.y - s2.y)) / (-s2_x * s1_y + s1_x * s2_y);
    float t = ( s2_x * (s1.y - s2.y) - s2_y * (s1.x - s2.x)) / (-s2_x * s1_y + s1_x * s2_y);

    return (s >= 0 && s <= 1 && t >= 0 && t <= 1);
}
