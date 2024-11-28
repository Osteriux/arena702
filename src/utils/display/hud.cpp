#include "hud.h"

HUD::HUD(sf::RenderWindow* window, Player* player, Score* score)
{
    this->score = score;
    this->window = window;
    if (!font.loadFromFile("assets/font.ttf"))
    {
        throw std::runtime_error("Could not load font");
    }
    this->player = player;

    this->background = sf::RectangleShape(sf::Vector2f(window->getSize().x, 50));
    this->background.setFillColor(sf::Color::Black);

    this->textFps = sf::Text("FPS: ", font);
    this->textFps.setFillColor(sf::Color(127, 127, 127));
    this->textFps.setPosition(580, 7);

    this->textHealth = sf::Text("", font);
    this->textHealth.setFillColor(sf::Color::Red);
    this->textHealth.setPosition(320, 7);
    this->healthBar = sf::RectangleShape(sf::Vector2f(200, 20));
    this->healthBar.setFillColor(sf::Color::Red);
    this->healthBar.setPosition(370, 15);

    this->textScore = sf::Text("Score: ", font);
    this->textScore.setFillColor(sf::Color::White);
    this->textScore.setPosition(10, 7);
}

void HUD::draw() const
{
    window->draw(background);
    window->draw(textHealth);
    window->draw(healthBar);
    window->draw(textFps);
    window->draw(textScore);
}

void HUD::update(float dt)
{
    textFps.setString("FPS: " + std::to_string((int)(1.0f / dt)));
    textHealth.setString(std::to_string(player->getHealth()));
    healthBar.setSize(sf::Vector2f(player->getHealth() * 2, 20));
    textScore.setString("Score: " + std::to_string(score->getScore()));
}
