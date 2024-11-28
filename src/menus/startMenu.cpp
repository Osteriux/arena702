#include "startMenu.h"

StartMenu::StartMenu(sf::Vector2u windowSize, bool *isGameStarted, bool *isGameExit)
    : Menu(windowSize)
{
    this->isGameStarted = isGameStarted;
    this->isGameExit = isGameExit;

    sf::Font font;
    font.loadFromFile("assets/font.ttf");

    title = sf::Text("arena702", font);
    // title.setCharacterSize(100);
    title.setFillColor(sf::Color::White);
    title.setPosition(100, 100);

    start = sf::Text("Start -> Enter", font);
    // start.setCharacterSize(50);
    start.setFillColor(sf::Color::White);
    start.setPosition(300, 300);

    exit = sf::Text("Exit -> Esc", font);
    // exit.setCharacterSize(50);
    exit.setFillColor(sf::Color::White);
    exit.setPosition(300, 500);
}

void StartMenu::draw(sf::RenderWindow& window)
{
    window.draw(background);
    // window.draw(title);
    std::cout << "draw start menu" << std::endl;
    // window->draw(start);
    // window->draw(exit);
}

void StartMenu::update()
{
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
