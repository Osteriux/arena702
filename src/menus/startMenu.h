#pragma once
#include "menu.h"

class StartMenu : public Menu
{
private:
    sf::Text title;
    sf::Text start;
    sf::Text exit;

    bool* isGameStarted;
    bool* isGameExit;

public:
    StartMenu(sf::Vector2u windowSize, bool* isGameStarted, bool* isGameExit);
    void draw(sf::RenderWindow& window) override;
    void update() override;
    void handleInput(sf::Keyboard::Key key, bool isPressed) override;
    ~StartMenu() = default;
};