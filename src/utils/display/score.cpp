#include "score.h"
#include "../factory/enemyFactory.h"
#include "../manager/gameObjectManager.h"

Score::Score()
{
    score = 0;
    stage = 0;
}

void Score::setEnemyFactory(EnemyFactory* enemyFactory)
{
    this->enemyFactory = enemyFactory;
}

void Score::setGameObjectManager(GameObjectManager* gameObjectManager)
{
    this->gameObjectManager = gameObjectManager;
}

void Score::setPlayer(Player* player)
{
    this->player = player;
}

unsigned int Score::getScore() const
{
    return score;
}

void Score::checkStage()
{
    if(score >= STAGE_7)
    {
        enemyFactory->setGameStage(7);
        if(stage < 7)
        {
            gameObjectManager->addOnomatope(std::make_unique<StageChange>(7));
            gameObjectManager->spawnRocketShip();
            gameObjectManager->spawnShieldShip();
            enemyFactory->setGameStage(6);
            stage = 7;
            player->upgradeWeapon(stage);
        }
    }
    else if(score >= STAGE_6)
    {
        if(stage < 6){
            gameObjectManager->addOnomatope(std::make_unique<StageChange>(6));
            enemyFactory->setGameStage(6);
            stage = 6;
            player->upgradeWeapon(stage);
        }
    }
    else if(score >= STAGE_5)
    {
        if(stage < 5)
        {
            enemyFactory->setGameStage(5);
            gameObjectManager->addOnomatope(std::make_unique<StageChange>(5));
            gameObjectManager->spawnShieldShip();
            stage = 5;
            player->upgradeWeapon(stage);
        }
    }
    else if(score >= STAGE_4)
    {
        if(stage < 4){
            gameObjectManager->addOnomatope(std::make_unique<StageChange>(4));
            enemyFactory->setGameStage(4);
            stage = 4;
            player->upgradeWeapon(stage);
        }
    }
    else if(score >= STAGE_3)
    {
        if(stage < 3)
        {
            enemyFactory->setGameStage(3);
            gameObjectManager->addOnomatope(std::make_unique<StageChange>(3));
            gameObjectManager->spawnRocketShip();
            stage = 3;
            player->upgradeWeapon(stage);
        }
    }
    else if(score >= STAGE_2)
    {
        if(stage < 2){
            gameObjectManager->addOnomatope(std::make_unique<StageChange>(2));
            enemyFactory->setGameStage(2);
            stage = 2;
            player->upgradeWeapon(stage);
        }
    }
    else if(score >= STAGE_1)
    {
        if(stage < 1){
            gameObjectManager->addOnomatope(std::make_unique<StageChange>(1));
            enemyFactory->setGameStage(1);
            stage = 1;
            player->upgradeWeapon(stage);
        }
    }
}

int Score::getEnemyCap() const
{
    switch (stage)
    {
    case 0:
        return 5;
    case 1:
        return 10;
    case 2:
        return 12;
    case 3:
        return 17;
    case 4:
        return 22;
    case 5:
        return 25;
    case 6:
        return 30;
    case 7:
        return 40;
    default:
        return 10;
    }
}

void Score::addScore(unsigned int score)
{
    this->score += score;
    checkStage();
}

void Score::reset()
{
    score = 0;
    stage = 0;
}