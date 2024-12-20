#include "player.h"
#include "../utils/manager/gameObjectManager.h"

Player::Player(GameObjectManager* gameObjectManager, sf::Vector2u windowSize, bool* isGameOver)
    : Entity(11.5f, gameObjectManager, windowSize, windowSize.x/2,  windowSize.y/2, 1000.0f, 500.0f, 540, 100, 
             new Gun(20, 1000.0f, 0.2f, sf::Color::White, 1), 3.0f, sf::Color(255, 255, 255, 127), 1.0f)
{
    this->weaponDamage = 20;
    this->isGameOver = isGameOver;
    this->attacking = false;
    this->texture.loadFromFile("assets/player.png");
    this->setTexture(this->texture, true);
    this->setOrigin(14.5, 13.5);
}

void Player::setAttacking(bool attacking)
{
    this->attacking = attacking;
}

void Player::setMoving(float moving)
{
    if(moving == 1.0f && this->moving >= 1.0f)
    {
        float delta = 2.0f - this->moving;
        this->moving += delta / 5.0f;
    }else{
        this->moving = moving;
    }
}

void Player::upgradeWeapon(int damage)
{
    this->weaponDamage += damage;
    this->weapon->setDamage(this->weaponDamage);
}

bool Player::update(float dt, sf::Vector2f mousePosition)
{
    this->orientate(mousePosition, dt);
    this->applyAcceleration();
    this->move(dt);
    if(this->attacking)
    {
        this->attack();
    }
    this->weapon->update(dt);
    this->iFrames(dt);
    return false;
}

void Player::attack()
{
    this->gameObjectManager->addPlayerAttack(this->weapon->attack(this));
}

void Player::dash()
{
    // breaks collision
    // this->setPosition(this->getPosition() + direction * 150.0f);
}

void Player::takeDamage(int damage)
{
    if(currIframes <= 0)
    {
        this->health -= damage;
        currIframes = iframes;
        this->setColor(sf::Color(255, 255, 255, 150));
        if(this->health <= 0)
        {
            this->onDeath();
        }
        this->gameObjectManager->addOnomatope(std::make_unique<Onomatope>(std::to_string(damage), sf::Color::Red, this->getPosition(), 0.5f));
    }
}

void Player::heal(int heal)
{
    this->health += heal;
    if(this->health > 100)
    {
        this->health = 100;
    }
    this->gameObjectManager->addOnomatope(std::make_unique<Onomatope>(std::to_string(heal), sf::Color::Green, this->getPosition(), 0.5f));
}

void Player::onCollision(Entity* entity)
{
    if(typeid(*entity) == typeid(Enemy))
    {
        this->bounceBack(entity);
    }
}

void Player::reset()
{
    this->setPosition(200.0f, 200.0f);
    this->health = 100;
    this->weapon->reset();
}

void Player::onDeath()
{
    *this->isGameOver = true;
}

void Player::debug()
{
    // std::cout << "Player position: " << this->getPosition().x << ", " << this->getPosition().y << std::endl;
    // std::cout << "Player direction: " << this->direction.x << ", " << this->direction.y << std::endl;
    // float currentSpeed = std::sqrt(this->velocity.x * this->velocity.x + this->velocity.y * this->velocity.y);
    // std::cout << "Speed: " << currentSpeed << std::endl;
}
