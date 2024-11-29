#include "enemyStatSupplier.h"

float* EnemyStatSupplier::getBasicStat(int gameStage)
{
    float* stats = new float[4];
    stats[0] = 50.0f + gameStage * 10.0f; // health
    stats[1] = 500.0f + gameStage * 50.0f; // speed
    stats[2] = 10.0f + gameStage * 1.0f; // damage
    stats[3] = 10.0f + gameStage * -1.0f; // fire rate
    return stats;
}

float* EnemyStatSupplier::getEliteStat(int gameStage)
{
    float* stats = new float[4];
    stats[0] = 100.0f + gameStage * 20.0f; // health
    stats[1] = 500.0f + gameStage * 25.0f; // speed
    stats[2] = 13.0f + gameStage * 2.0f; // damage
    stats[3] = 10.0f + gameStage * -0.5f; // fire rate
    return stats;
}

float* EnemyStatSupplier::getKamikazeStat(int gameStage)
{
    float* stats = new float[4];
    stats[0] = 10.0f + gameStage * 15.0f; // health
    stats[1] = 1000.0f + gameStage * 100.0f; // speed
    stats[2] = 15.0f + gameStage * 5.0f; // damage
    stats[3] = 0.0f; // fire rate (non applicable)
    return stats;
}

float* EnemyStatSupplier::getRocketStat(int gameStage)
{
    float* stats = new float[4];
    stats[0] = 200.0f + gameStage * 50.0f; // health
    stats[1] = 200.0f + gameStage * 5.0f; // speed
    stats[2] = 15.0f + gameStage * 3.0f; // damage
    stats[3] = 15.0f + gameStage * -1.0f; // fire rate
    return stats;
}

float* EnemyStatSupplier::getShieldStat(int gameStage)
{
    float* stats = new float[4];
    stats[0] = 300.0f + gameStage * 100.0f; // health
    stats[1] = 200.0f + gameStage * 10.5f; // speed
    stats[2] = 20.0f + gameStage * 5.0f; // damage
    stats[3] = 10.0f + gameStage * -1.0f; // fire rate
    return stats;
}

float* EnemyStatSupplier::getEnemyStat(int gameStage, EnemyFactory::EnemyType enemyType)
{
    switch (enemyType)
    {
    case EnemyFactory::EnemyType::Basic:
        return getBasicStat(gameStage);
    case EnemyFactory::EnemyType::Elite:
        return getBasicStat(gameStage);
    case EnemyFactory::EnemyType::Kamikaze:
        return getKamikazeStat(gameStage);
    case EnemyFactory::EnemyType::Rocket:
        return getRocketStat(gameStage);
    case EnemyFactory::EnemyType::Shield:
        return getShieldStat(gameStage);
    default:
        return nullptr;
    }
}