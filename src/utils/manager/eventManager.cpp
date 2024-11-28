#include "eventManager.h"
#include "gameObjectManager.h"

EventManager::EventManager(Player* player)
{
    this->player = player;
}

void EventManager::handleEvent(sf::Event event) const
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        handleKeyDownEvent(event.key);
        break;
    case sf::Event::KeyReleased:
        handleKeyUpEvent(event.key);
        break;
    case sf::Event::MouseButtonPressed:
        handleMouseDownEvent(event.mouseButton);
        break;
    case sf::Event::MouseButtonReleased:
        handleMouseUpEvent(event.mouseButton);
        break;
    default:
        break;
    }
}

void EventManager::handleKeyDownEvent(sf::Event::KeyEvent keyEvent) const
{
    switch (keyEvent.code)
    {
    case sf::Keyboard::Z:
        this->player->setMoving(1.0f);
        break;
    case sf::Keyboard::S:
        this->player->setMoving(-1.0f);
        break;
    case sf::Keyboard::LShift:
        this->player->dash();
        break;
    case sf::Keyboard::R:
        this->player->gameObjectManager->spawnShieldShip();
        break;
    default:
        break;
    }
}

void EventManager::handleKeyUpEvent(sf::Event::KeyEvent keyEvent) const
{
    switch (keyEvent.code)
    {
    case sf::Keyboard::Z:
    case sf::Keyboard::S:
        this->player->setMoving(0.0f);
        break;
    default:
        break;
    }
}

void EventManager::handleMouseDownEvent(sf::Event::MouseButtonEvent mouseButtonEvent) const
{
    switch (mouseButtonEvent.button)
    {
    case sf::Mouse::Left:
        this->player->setAttacking(true);
        break;
    default:
        break;
    }
}

void EventManager::handleMouseUpEvent(sf::Event::MouseButtonEvent mouseButtonEvent) const
{
    switch (mouseButtonEvent.button)
    {
    case sf::Mouse::Left:
        this->player->setAttacking(false);
        break;
    case sf::Mouse::Right:
        this->player->debug();
        break;
    default:
        break;
    }
}
