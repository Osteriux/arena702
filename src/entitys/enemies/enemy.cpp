#include "enemy.h"
#include "../../utils/manager/gameObjectManager.h"

Enemy::Enemy(float size, int health, Weapon* weapon, float speed, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score)
    : Entity(size,gameObjectManager, sf::Vector2u(), position.x, position.y, speed, 1000.0f, 500, health,
             weapon, 0.2f, sf::Color(255, 127, 127, 127), 0.5f)
{
    this->moving = 1;
    this->score = score;
    this->texture.loadFromFile(texturePath);
    this->setTexture(this->texture, true);
    this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
}

void Enemy::attemptAttack(sf::Vector2f playerPosition)
{
    sf::Vector2f vect = playerPosition - this->getPosition();

    bool inRange = false;
    float distance = sqrt(vect.x * vect.x + vect.y * vect.y);
    if(distance < this->weapon->getRange())
    {
        inRange = true;
    }

    bool facingPlayer = false;
    float angle = atan2(direction.y, direction.x) * 180 / M_PI;
    float currentRotation = this->getRotation();
    float angleDifference = std::abs(currentRotation - angle);
    if (angleDifference > 180)
    {
        angleDifference = 360 - angleDifference;
    }
    if(angleDifference < 30.0f)
    {
        facingPlayer = true;
    }

    if(inRange && facingPlayer)
    {
        this->attack();
    }
}

bool Enemy::update(float dt, sf::Vector2f playerPosition)
{
    this->orientate(playerPosition, dt);
    this->applyAcceleration();
    this->move(dt);
    this->attemptAttack(playerPosition);
    this->weapon->update(dt);
    this->iFrames(dt);
    return health <= 0;
}

void Enemy::attack()
{
    this->gameObjectManager->addEnemyAttack(this->weapon->attack(this));
}

void Enemy::takeDamage(int damage)
{
    if(currIframes <= 0)
    {
        this->health -= damage;
        currIframes = iframes;
        if(this->health <= 0)
        {
            onDeath();
        }
        score->addScore(damage);
        this->gameObjectManager->addOnomatope(std::make_unique<Onomatope>(std::to_string(damage), sf::Color::White, this->getPosition(), 0.5f));
    }
}

void Enemy::onCollision(Entity* entity)
{
    if(typeid(*entity) == typeid(Player))
    {
        entity->takeDamage(5);
        this->takeDamage(20);
    }
    this->bounceBack(entity);
}

void Enemy::move(float dt)
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

    // std::cout << "velocity: " << velocity.x << ", " << velocity.y << std::endl;
    // update position with velocity
    sf::Vector2f position = this->getPosition();
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    this->setPosition(position);

    // reset acceleration
    acceleration = sf::Vector2f(0.0f, 0.0f);
}

void Enemy::onDeath()
{
    this->gameObjectManager->addAnimation(std::make_unique<AnimationLine>("assets/boom.png", 11, sf::IntRect(0, 0, 250, 250), 0.1f, this->getPosition(), sf::Vector2f(0.3f, 0.3f)));
}