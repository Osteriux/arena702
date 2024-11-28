#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Menu : public sf::Sprite
{
protected:
    sf::RectangleShape background;

public:
    Menu(sf::Vector2u windowSize);
    virtual void draw(sf::RenderWindow& window);
    virtual void update() = 0;
    virtual void handleInput(sf::Keyboard::Key key, bool isPressed) = 0;
    ~Menu() = default;
};
