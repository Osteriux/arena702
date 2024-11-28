#include "menu.h"

Menu::Menu(sf::RenderWindow* window, sf::Vector2u windowSize)
{
    this->window = window;
    background.setSize(sf::Vector2f(windowSize.x, windowSize.y));
    background.setFillColor(sf::Color(0, 0, 0, 150));
    
    if (!font.loadFromFile("assets/font.ttf"))
    {
        throw std::runtime_error("Could not load font");
    }
}

void Menu::draw() const
{
    window->draw(background);
}