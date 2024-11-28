#include "gameObjectManager.h"
#include "../../entitys/player.h"

GameObjectManager::GameObjectManager(sf::RenderWindow* window, sf::Vector2u arenaSize, Score* score)
{
    this->window = window;
    this->arenaSize = arenaSize;
    this->random = CustomRandom(arenaSize);
    this->score = score;
    this->enemyFactory = new EnemyFactory(score);
    this->score->setEnemyFactory(enemyFactory);
    this->score->setGameObjectManager(this);
}

void GameObjectManager::setPlayer(Player* player)
{
    this->player = player;
}

sf::Vector2u GameObjectManager::getArenaSize() const
{
    return arenaSize;
}

void GameObjectManager::addEnemy(std::unique_ptr<Enemy> enemy)
{
    if(enemy != nullptr){
        enemiesBuffer.push_back(std::move(enemy));
    }
}

void GameObjectManager::addPlayerAttack(std::unique_ptr<Attack> playerAttack)
{
    if(playerAttack != nullptr){
        playerAttacks.push_back(std::move(playerAttack));
    }
}

void GameObjectManager::addEnemyAttack(std::unique_ptr<Attack> enemyAttack)
{
    if(enemyAttack != nullptr){
        enemyAttacks.push_back(std::move(enemyAttack));
    }
}

void GameObjectManager::addAnimation(std::unique_ptr<Animation> animation)
{
    if(animation != nullptr){
        animations.push_back(std::move(animation));
    }
}

void GameObjectManager::addOnomatope(std::unique_ptr<Onomatope> onomatope)
{
    if(onomatope != nullptr){
        onomatopes.push_back(std::move(onomatope));
    }
}

void GameObjectManager::addItem(std::unique_ptr<Item> item)
{
    if(item != nullptr){
        items.push_back(std::move(item));
    }
}

void GameObjectManager::draw() const
{
    // draw enemies attacks
    for (auto& eatt : enemyAttacks)
    {
        window->draw(*eatt.get());
    }
    // draw enemies
    for(auto& enemy : enemies)
    {
        window->draw(*enemy.get());
    }
    // draw player attacks
    for (auto& patt : playerAttacks)
    {
        window->draw(*patt.get());
    }
    // draw player
    window->draw(*player);
    // draw animations
    for (auto& animation : animations)
    {
        window->draw(*animation.get());
    }
    // draw onomatopes
    for (auto& onomatope : onomatopes)
    {
        onomatope->draw(window);
    }
    // draw items
    for (auto& item : items)
    {
        window->draw(*item.get());
    }
}

void GameObjectManager::collide()
{
    sf::FloatRect phitbox = player->getHitbox();
    // enemy collision
    for (auto& e : enemies)
    {
        sf::FloatRect ehitbox = e->getGlobalBounds();
        // with player attacks
        for (auto& patt : playerAttacks)
        {
            if(patt->collidesWith(ehitbox))
            {
                patt->onCollision(e.get());
            }
        }
        // with other enemies
        for(auto& e2 : enemies)
        {
            if(e.get() == e2.get()) continue;
            if(e.get()->collidesWith(e2.get()))
            {
                e->onCollision(e2.get());
                e2->onCollision(e.get());
            }
        }
        // with player
        if(player->collidesWith(e.get()))
        {
            e->onCollision(player);
            player->onCollision(e.get());
        }
    }
    // player collide with enemies atttacks
    for (auto& eatt : enemyAttacks)
    {
        if(eatt->collidesWith(phitbox))
        {
            eatt->onCollision(player);
        }
    }

    // player collide with items
    for (auto& item : items)
    {
        if(item->getGlobalBounds().intersects(player->getGlobalBounds()))
        {
            item->onPickup(player);
        }
    }
}

void GameObjectManager::spawnEnemy()
{
    if(enemies.size() < score->getEnemyCap()){
        if(random.doSpawnEnemy()){
            EnemyFactory::EnemyType etype = random.isEnemyElite() ? EnemyFactory::EnemyType::Elite : EnemyFactory::EnemyType::Basic;
            WeaponFactory::WeaponType wtype = random.isEnemyRanged() ? WeaponFactory::WeaponType::Projectile : WeaponFactory::WeaponType::CLoseCombat;
            std::unique_ptr<Enemy> enemy;
            if(etype == EnemyFactory::EnemyType::Elite)
            {
                enemy = enemyFactory->createEnemy(etype, wtype, 
                    this, arenaSize, random.getRandomPosition());
            }else{
                enemy = enemyFactory->createEnemy(etype, wtype, 
                    this, arenaSize, random.getRandomPosition());
            }
            addEnemy(std::move(enemy));
        }
    }
}

void GameObjectManager::spawnKamikaze(sf::Vector2f position)
{
    addEnemy(enemyFactory->createEnemy(EnemyFactory::EnemyType::Kamikaze, WeaponFactory::WeaponType::CLoseCombat, 
            this, arenaSize, position));
}

void GameObjectManager::spawnRocketShip()
{
    addEnemy(enemyFactory->createEnemy(EnemyFactory::EnemyType::Rocket, WeaponFactory::WeaponType::Projectile, 
            this, arenaSize, random.getRandomBossPosition()));
}

void GameObjectManager::spawnShieldShip()
{
    addEnemy(enemyFactory->createEnemy(EnemyFactory::EnemyType::Shield, WeaponFactory::WeaponType::Laser, 
            this, arenaSize, random.getRandomBossPosition()));
}

void GameObjectManager::spawnItem()
{
    if(items.size() < 2){
        if(random.doSpawnItem()){
            addItem(ItemFactory::createItem(ItemFactory::ItemType::HealBall, random.getRandomItemPosition()));
        }
    }
}

void GameObjectManager::update(float dt, sf::Vector2i mousePosition)
{
    spawnEnemy();
    spawnItem();
    sf::Vector2f playerPos = player->getPosition();
    // Update enemies & remove if nedded
    auto ennIt = std::remove_if(enemies.begin(), enemies.end(),
        [dt, playerPos](const std::unique_ptr<Enemy>& enemie) {
            return enemie->update(dt, playerPos);
        }
    );
    enemies.erase(ennIt, enemies.end());
    // add enemies from buffer
    for(auto& enemy : enemiesBuffer)
    {
        enemies.push_back(std::move(enemy));
    }
    enemiesBuffer.clear();

    // Update player
    player->update(dt, sf::Vector2f(mousePosition));

    // Update player attacks & remove if nedded
    auto pattIt = std::remove_if(playerAttacks.begin(), playerAttacks.end(),
        [dt](const std::unique_ptr<Attack>& patt) {
            return patt->update(dt);
        }
    );
    playerAttacks.erase(pattIt, playerAttacks.end());

    // Update enemies attacks & remove if nedded
    auto eattIt = std::remove_if(enemyAttacks.begin(), enemyAttacks.end(),
        [dt](const std::unique_ptr<Attack>& eatt) {
            return eatt->update(dt);
        }
    );
    enemyAttacks.erase(eattIt, enemyAttacks.end());

    // Update animations & remove if nedded
    auto animIt = std::remove_if(animations.begin(), animations.end(),
        [dt](const std::unique_ptr<Animation>& anim) {
            return anim->update(dt);
        }
    );
    animations.erase(animIt, animations.end());

    // Update onomatopes & remove if nedded
    auto onoIt = std::remove_if(onomatopes.begin(), onomatopes.end(),
        [dt](const std::unique_ptr<Onomatope>& ono) {
            return ono->update(dt);
        }
    );
    onomatopes.erase(onoIt, onomatopes.end());

    // Update items & remove if nedded
    auto itemIt = std::remove_if(items.begin(), items.end(),
        [dt](const std::unique_ptr<Item>& item) {
            return item->update(dt);
        }
    );
    items.erase(itemIt, items.end());
}

GameObjectManager::~GameObjectManager()
{
    // delete enemies
    enemies.clear();
    // delete player attacks
    playerAttacks.clear();
    // delete enemies attacks
    enemyAttacks.clear();
    // delete animations
    animations.clear();
    // delete onomatopes
    onomatopes.clear();
    // delete items
    items.clear();
}