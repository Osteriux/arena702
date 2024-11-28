#include "menu.h"

Menu::Menu(sf::Vector2u windowSize)
{
    background.setSize(sf::Vector2f(windowSize.x, windowSize.y));
    background.setFillColor(sf::Color(0, 0, 0, 150));
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(background);
}