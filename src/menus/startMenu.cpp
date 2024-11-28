#include "startMenu.h"

StartMenu::StartMenu(sf::RenderWindow* window, sf::Vector2u windowSize, bool *isGameStarted, bool *isGameExit)
    : Menu(window, windowSize)
{
    this->isGameStarted = isGameStarted;
    this->isGameExit = isGameExit;

    title = sf::Text("arena702", font);
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(100);
    title.setPosition(100, 100);

    start = sf::Text("Start -> Enter", font);
    start.setCharacterSize(50);
    start.setFillColor(sf::Color::White);
    start.setPosition(200, 300);

    exit = sf::Text("Exit -> Esc", font);
    exit.setCharacterSize(50);
    exit.setFillColor(sf::Color::White);
    exit.setPosition(200, 500);
}

void StartMenu::draw() const
{
    Menu::draw();
    std::cout << "title : "<< title.getPosition().x << std::endl;
    window->draw(title);
    std::cout << "draw start menu" << std::endl;
    window->draw(start);
    window->draw(exit);
}

void StartMenu::handleInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Enter && isPressed)
    {
        *isGameStarted = true;
    }
    else if (key == sf::Keyboard::Escape && isPressed)
    {
        *isGameExit = true;
    }
}
