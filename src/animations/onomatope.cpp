#include "onomatope.h"
#include <iostream>

Onomatope::Onomatope(std::string text, sf::Color color, sf::Vector2f position, float duration, int size)
{
    this->text.setString(text);
    this->font.loadFromFile("assets/font.ttf");
    this->text.setFont(this->font);
    this->text.setCharacterSize(size);
    this->text.setFillColor(color);
    this->text.setPosition(position);
    this->duration = duration;
}

void Onomatope::draw(sf::RenderWindow* window) const
{
    window->draw(this->text);
}

bool Onomatope::update(float dt)
{
    this->duration -= dt;
    this->text.move(0, -50.0f * dt);
    return this->duration <= 0;
}