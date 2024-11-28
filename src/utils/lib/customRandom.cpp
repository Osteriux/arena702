#include "customRandom.h"
#include <cmath>
#include <iostream>

CustomRandom::CustomRandom(sf::Vector2u arenaSize)
{
    this->arenaSize = arenaSize;
    this->gen.seed(std::random_device{}());
    this->spawnDist = std::uniform_int_distribution<int>(0, 10000);
    this->eliteDist = std::uniform_int_distribution<int>(0, 100);
    this->rangedDist = std::uniform_int_distribution<int>(0, 100);
    this->sideDist = std::uniform_int_distribution<int>(0, 3);
    this->posDist = std::uniform_real_distribution<float>(0, 100);
    this->spawnItemDist = std::uniform_int_distribution<int>(0, 10000);
    this->itemXDist = std::uniform_real_distribution<float>(65, arenaSize.x-15);
    this->itemYDist = std::uniform_real_distribution<float>(15, arenaSize.y-15);
}

sf::Vector2f CustomRandom::getRandomPosition()
{
    int side = sideDist(gen);
    // 0: top, 1: right, 2: bottom, 3: left
    int xm = side == 3 ? -1 : 1;
    int ym = side == 0 ? -1 : 1;
    float x = side == 1 ? arenaSize.x : 0;
    float y = side == 2 ? arenaSize.x : 0;
    x += posDist(gen) * xm;
    y += posDist(gen) * ym;
    return sf::Vector2f(x, y+50); // +50 to account for hud
}

sf::Vector2f CustomRandom::getRandomBossPosition()
{
    int side = sideDist(gen);
    // 0: top, 1: right, 2: bottom, 3: left
    switch (side)
    {
    case 0:
        return sf::Vector2f(posDist(gen), -75);
    case 1:
        return sf::Vector2f(arenaSize.x + 75, posDist(gen));
    case 2:
        return sf::Vector2f(posDist(gen), arenaSize.y + 75);
    case 3:
        return sf::Vector2f(-75, posDist(gen));
    default:
        return sf::Vector2f(posDist(gen), -75);
    }
}

sf::Vector2f CustomRandom::getRandomItemPosition()
{
    return sf::Vector2f(itemXDist(gen), itemYDist(gen));
}

bool CustomRandom::doSpawnItem()
{
    return spawnItemDist(gen) < 1;
}

bool CustomRandom::doSpawnEnemy()
{
    return spawnDist(gen) < 10;
}

bool CustomRandom::isEnemyElite()
{
    return eliteDist(gen) < 5;
}

bool CustomRandom::isEnemyRanged()
{
    return rangedDist(gen) < 15;
}