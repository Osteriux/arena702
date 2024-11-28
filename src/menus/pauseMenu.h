#pragma once
#include "menu.h"

class PauseMenu : public Menu
{
private:
    sf::Text title;
    sf::Text resume;
    sf::Text exit;

    bool* isGamePaused;
    bool* isGameExit;

public:
    PauseMenu(sf::RenderWindow* window, sf::Vector2u windowSize, bool* isGamePaused, bool* isGameExit);
    void draw() const override;
    void handleInput(sf::Keyboard::Key key, bool isPressed) override;
    ~PauseMenu() = default;

};
