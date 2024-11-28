#pragma once
#include "attack.h"
#include "../../entitys/entity.h"

class Laser : public Attack {
private:
    float distance;
    float offset;

    bool lineIntersectsRect(sf::Vector2f p1, sf::Vector2f p2, sf::FloatRect rect) const;
    bool lineIntersectsLine(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f p4) const;
public:
    Laser(Entity* owner, float damage, float duration, sf::Color color, float offset);
    bool collidesWith(const sf::FloatRect& rectangle) override;
    void onCollision(Entity* entity) override;
    bool update(float dt) override;
    ~Laser() = default;
};
