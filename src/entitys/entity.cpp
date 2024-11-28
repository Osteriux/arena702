#include "entity.h"
#include "player.h"

Entity::Entity(float size, GameObjectManager* gameObjectManager, sf::Vector2u windowSize, float x, float y, float speed, float maxSpeed, int rotationSpeed, int health, Weapon* weapon, float iframes, sf::Color iFramesColor, float bounceFactor)
{
    this->size = size;
    this->gameObjectManager = gameObjectManager;
    this->windowSize = windowSize;
    this->setPosition(x, y);
    this->speed = speed;
    this->maxSpeed = maxSpeed;
    this->rotationSpeed = rotationSpeed;
    this->health = health;
    this->moving = 0;
    this->direction = sf::Vector2f(0.0f, 0.0f);
    this->velocity = sf::Vector2f(0.0f, 0.0f);
    this->acceleration = sf::Vector2f(0.0f, 0.0f);
    this->weapon = weapon;
    this->iframes = iframes;
    this->currIframes = 0.0f;
    this->iFrameColor = iFramesColor;
    this->bounceFactor = bounceFactor;
}

int Entity::getHealth() const
{
    return this->health;
}

sf::Vector2f Entity::getDirection() const
{
    return this->direction;
}

float Entity::getSize() const
{
    return this->size;
}

void Entity::setMoving(float moving)
{
    this->moving = moving;
}

sf::FloatRect Entity::getHitbox() const
{
    sf::FloatRect hitbox = this->getGlobalBounds();
    hitbox.width /= 2;
    hitbox.height /= 2;
    hitbox.left += hitbox.width / 2;
    hitbox.top += hitbox.height / 2;
    return hitbox;
}

void Entity::applyAcceleration()
{
    float accelFactor = moving >= 1.0f ? 1.0f : 0.3f;
    this->acceleration += direction * (speed * accelFactor * moving);
}

void Entity::orientate(sf::Vector2f target, float dt)
{
    float tx = target.x;
    float ty = target.y;
    float sx = this->getPosition().x;
    float sy = this->getPosition().y;

    // get angle between player and mouse in radiant
    float Tangle = atan2(ty - sy, tx - sx) * 180 / M_PI;
    float Cabgle = this->getRotation();
    float angleDiff = Tangle - Cabgle;
    if (angleDiff > 180)
    {
        angleDiff -= 360;
    }else if (angleDiff < -180)
    {
        angleDiff += 360;
    }

    // apply rotation
    float rotStep = rotationSpeed * dt;
    if(std::abs(angleDiff) < rotStep)
    {
        this->setRotation(Tangle);
    }else{
        this->setRotation(Cabgle + rotStep * (angleDiff > 0 ? 1 : -1));
    }
    
    float CRadAngle = this->getRotation() * M_PI / 180;
    this->direction = sf::Vector2f(cosf(CRadAngle), sinf(CRadAngle));
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if(length != 0)
    {
        direction /= length;
    }
}

void Entity::move(float dt)
{
    // update velocity with acceleration
    velocity += acceleration * dt;

    // limit velocity
    float velocityMagnitude = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    if (velocityMagnitude > maxSpeed)
    {
        velocity /= velocityMagnitude;
        velocity *= maxSpeed;
    }

    // apply friction
    velocity *= 0.999f;

    // update position with velocity
    sf::Vector2f position = this->getPosition();
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
    this->setPosition(position);
    if (position.x < -30)
    {
        position.x += windowSize.x + 60;
    }
    else if (position.x > windowSize.x + 30)
    {
        position.x -= windowSize.x + 60;
    }
    if (position.y < -30)
    {
        position.y += windowSize.y + 60;
    }
    else if (position.y > windowSize.y + 30)
    {
        position.y -= windowSize.y + 60;
    }

    this->setPosition(position);

    // reset acceleration
    acceleration = sf::Vector2f(0.0f, 0.0f);
}

void Entity::iFrames(float dt)
{
    if(currIframes > 0)
    {
        currIframes -= dt;
        if(currIframes <= 0)
        {
            currIframes = 0;
            // reset color
            this->setColor(sf::Color(255, 255, 255, 255));
        }
        if((int)(currIframes * 10) % 2 == 0)
        {
            this->setColor(sf::Color(255, 255, 255, 255));
        }else{
            this->setColor(this->iFrameColor);
        }
    }
}

void Entity::bounceBack(Entity* entity)
{
        sf::Vector2f collisionNormal = this->getPosition() - entity->getPosition();
        float length = std::sqrt(collisionNormal.x * collisionNormal.x + collisionNormal.y * collisionNormal.y);
        if (length != 0)
        {
            collisionNormal /= length; // normalize clooision vector
        }
        // allow some clipping
        this->setPosition(this->getPosition() + (collisionNormal * 10.0f));
        // bounce back
        float currSpeed = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
        float entitySpeed = std::sqrt(entity->velocity.x * entity->velocity.x + entity->velocity.y * entity->velocity.y);

        // pass through if both entities are not moving
        if(currSpeed < 30.0f && entitySpeed < 30.0f)
        {
            return;
        }

        this->velocity = collisionNormal * currSpeed * bounceFactor * 1.2f;
        this->velocity = collisionNormal * currSpeed * bounceFactor;
}

bool Entity::collidesWith(Entity* entity)
{
    int minDistance = this->size + entity->getSize();
    sf::Vector2f distance = this->getPosition() - entity->getPosition();
    float length = std::sqrt(distance.x * distance.x + distance.y * distance.y);
    return length < minDistance;
}