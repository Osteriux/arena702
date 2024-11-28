#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Menu : public sf::Sprite
{
protected:
    sf::RectangleShape background;
    sf::RenderWindow* window;
    sf::Font font;

public:
    Menu(sf::RenderWindow* window, sf::Vector2u windowSize);
    virtual void draw() const;
    virtual void handleInput(sf::Keyboard::Key key, bool isPressed) = 0;
    ~Menu() = default;
};
