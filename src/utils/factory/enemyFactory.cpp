#include "enemyFactory.h"
#include "supplier/enemyStatSupplier.h"

EnemyFactory::EnemyFactory(Score* score)
{
    this->score = score;
};

void EnemyFactory::setGameStage(int stage)
{
    gameStage = stage;
};

std::unique_ptr<Enemy> EnemyFactory::createEnemy(EnemyType type, WeaponFactory::WeaponType weaponType, GameObjectManager* entityManager, sf::Vector2u windowSize, sf::Vector2f position)
{
    sf::Color color(255, 127, 127);
    float* stats = EnemyStatSupplier::getEnemyStat(gameStage, type);
    Weapon* weapon = WeaponFactory::createWeapon(weaponType, stats[2], stats[3], color);

    switch (type)
    {
    case EnemyType::Basic:
        return std::make_unique<Enemy>(12.5f, stats[0], weapon, stats[1], texturePath(type), entityManager, position, score);
    case EnemyType::Elite:
        return std::make_unique<Elite>(21.5f, stats[0], weapon, stats[1], texturePath(type), entityManager, position, score);
    case EnemyType::Kamikaze:
        return std::make_unique<Kamikaze>(12.5f, stats[0], stats[1], stats[2], weapon, texturePath(type), entityManager, position, score);
    case EnemyType::Rocket:
        return std::make_unique<RocketShip>(40.0f, stats[0], stats[1], stats[3], weapon, texturePath(type), entityManager, position, score);
    case EnemyType::Shield:
        return std::make_unique<ShieldShip>(49.0f, stats[0], stats[1], weapon, texturePath(type), entityManager, position, score);
    default:
        return std::make_unique<Enemy>(12.5f, stats[0], weapon, stats[1], texturePath(type), entityManager, position, score);
    }
};

std::string EnemyFactory::texturePath(EnemyType type)
{
    switch (type)
    {
    case EnemyType::Basic:
        return "assets/enemy1.png";
    case EnemyType::Elite:
        return "assets/enemy2.png";
    case EnemyType::Kamikaze:
        return "assets/mine0.png";
    case EnemyType::Rocket:
        return "assets/rocketship.png";
    case EnemyType::Shield:
        return "assets/shieldship.png";
    default:
        return "assets/enemy1.png";
    }
};
