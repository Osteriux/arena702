#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "src/entitys/player.h"
#include "src/utils/manager/eventManager.h"
#include "src/utils/manager/GameObjectManager.h"
#include "src/utils/display/hud.h"
#include "src/utils/display/score.h"
#include "src/menus/startMenu.h"


int main()
{
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(750, 800), "arena702");
    sf::Sprite background;
    sf::Texture bgTtexture;
    bgTtexture.loadFromFile("assets/bg.png");
    background.setTexture(bgTtexture);
    background.setScale(1.5, 1.5);
    background.setPosition(0, 50);
    sf::Vector2u arenaSize = background.getTexture()->getSize();
    arenaSize = sf::Vector2u(arenaSize.x * 1.5, (arenaSize.y * 1.5) + 50);
    
    Score score;
    GameObjectManager gameObjectManager(&window, arenaSize, &score);
    Player* player = new Player(&gameObjectManager, arenaSize);
    gameObjectManager.setPlayer(player);
    EventManager eventManager(player);
    HUD hud(&window, player, &score);

    bool isGameStarted = false;
    bool isGameExit = false;
    StartMenu startMenu(&window, window.getSize(), &isGameStarted, &isGameExit);

    bool isGamePaused = false;
    // TODO  pause menu

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || isGameExit)
            {
                window.close();
            }
            if(!isGameStarted){
                startMenu.handleInput(event.key.code, event.type == sf::Event::KeyPressed);
            }
            eventManager.handleEvent(event);
        }

        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        window.clear();

        window.draw(background);

        hud.draw();
        if(isGameStarted){ // main game loop
            gameObjectManager.draw();
            gameObjectManager.collide();
            gameObjectManager.update(dt, sf::Mouse::getPosition(window));
        }else{ // start menu loop
            window.draw(*player);
            std::cout << "isGameStarted: " << isGameStarted << std::endl;
            startMenu.draw();
            player->update(dt, sf::Vector2f(sf::Mouse::getPosition(window)));
        }
        hud.update(dt);

        window.display();
    }

    return 0;
}