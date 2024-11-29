#pragma once
#include "menu.h"

class GameOver : public Menu
{
private:
    sf::Text title;
    sf::Text restart;
    sf::Text exit;

    bool* isGameRestart;
    bool* isGameExit;
public:
    GameOver(sf::RenderWindow* window, sf::Vector2u windowSize, bool* isGameRestart, bool* isGameExit);
    void draw() const override;
    void handleInput(sf::Keyboard::Key key, bool isPressed) override;
    ~GameOver() = default;
};