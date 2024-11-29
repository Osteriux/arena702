#include "gameOver.h"

GameOver::GameOver(sf::RenderWindow* window, sf::Vector2u windowSize, bool* isGameRestart, bool* isGameExit)
    : Menu(window, windowSize)
{
    this->isGameRestart = isGameRestart;
    this->isGameExit = isGameExit;
    this->background.setFillColor(sf::Color::Black);

    title = sf::Text("Game Over", font);
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(100);
    title.setPosition(50, 100);

    restart = sf::Text("Restart -> Enter", font);
    restart.setCharacterSize(50);
    restart.setFillColor(sf::Color::White);
    restart.setPosition(120, 300);

    exit = sf::Text("Exit -> Esc", font);
    exit.setCharacterSize(50);
    exit.setFillColor(sf::Color::White);
    exit.setPosition(120, 500);
}

void GameOver::draw() const
{
    Menu::draw();
    window->draw(title);
    window->draw(restart);
    window->draw(exit);
}

void GameOver::handleInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Enter && isPressed)
    {
        *isGameRestart = true;
    }
    else if (key == sf::Keyboard::Escape && isPressed)
    {
        *isGameExit = true;
    }
}