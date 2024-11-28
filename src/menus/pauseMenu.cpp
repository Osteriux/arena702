#include "pauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow* window, sf::Vector2u windowSize, bool* isGamePaused, bool* isGameExit)
    : Menu(window, windowSize)
{
    this->isGamePaused = isGamePaused;
    this->isGameExit = isGameExit;

    title = sf::Text("Pause", font);
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(100);
    title.setPosition(200, 100);

    resume = sf::Text("Resume -> Espace", font);
    resume.setCharacterSize(40);
    resume.setFillColor(sf::Color::White);
    resume.setPosition(150, 300);

    exit = sf::Text("Exit -> Esc", font);
    exit.setCharacterSize(40);
    exit.setFillColor(sf::Color::White);
    exit.setPosition(150, 500);
}

void PauseMenu::draw() const
{
    Menu::draw();
    window->draw(title);
    window->draw(resume);
    window->draw(exit);
}

void PauseMenu::handleInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Space && isPressed)
    {
        *isGamePaused = false;
    }
    else if (key == sf::Keyboard::Escape && isPressed)
    {
        *isGameExit = true;
    }
}