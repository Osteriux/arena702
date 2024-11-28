/// @file entityManager.h
/// @brief Déclaration de la classe EntityManager pour la gestion des entités dans le jeu.
/// 
/// La classe EntityManager est responsable de la gestion des différentes entités
/// telles que les ennemis, les attaques, les animations et les onomatopées.
/// Elle maintient un pointeur vers un objet Player pour interagir avec le joueur
/// et un pointeur vers la fenêtre de jeu pour dessiner les entités.

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <random>
#include "../display/score.h"
#include "../factory/enemyFactory.h"
#include "../factory/itemFactory.h"
#include "../../entitys/player.h"
#include "../lib/customRandom.h"
#include "../../animations/animation.h"
#include "../../animations/onomatope.h"
#include "../../pickups/item.h"

class Player;

/// @brief gestionnaire des entités du jeu & autres. <br/>
/// La classe EntityManager est responsable de la gestion des différentes entités
/// telles que les ennemis, les attaques, les animations et les onomatopées.
/// Elle maintient un pointeur vers un objet Player pour interagir avec le joueur
/// et un pointeur vers la fenêtre de jeu pour dessiner les entités.
class GameObjectManager
{
private:
    /// @brief pointeur vers la fenêtre de jeu
    sf::RenderWindow* window;

    /// @brief pointeur vers le joueur
    Player* player;

    /// @brief score du joueur
    Score* score;

    /// @brief générateur de nombres aléatoires
    CustomRandom random;

    /// @brief taille de l'arène
    sf::Vector2u arenaSize;

    /// @brief liste des ennemis
    std::vector<std::unique_ptr<Enemy>> enemies;

    std::vector<std::unique_ptr<Enemy>> enemiesBuffer;

    /// @brief liste des attaques du joueur
    std::vector<std::unique_ptr<Attack>> playerAttacks;

    /// @brief liste des attaques des ennemis
    std::vector<std::unique_ptr<Attack>> enemyAttacks;

    /// @brief liste des animations
    std::vector<std::unique_ptr<Animation>> animations;

    /// @brief liste des onomatopées
    std::vector<std::unique_ptr<Onomatope>> onomatopes;

    /// @brief liste des items
    std::vector<std::unique_ptr<Item>> items;

    /// @brief fabrique d'ennemis
    EnemyFactory* enemyFactory;

    /// @brief fait apparaitre un ennemi aléatoirement
    void spawnEnemy();

    /// @brief fait apparaitre un item aléatoirement
    void spawnItem();
public:
    /// @brief Constructeur de EntityManager
    /// @param window pointeur vers la fenêtre de jeu
    /// @param background taille de l'arène
    /// @param score pointeur vers le score du joueur
    GameObjectManager(sf::RenderWindow* window, sf::Vector2u background, Score* score);

    /// @brief setteur du joueur
    /// @param player pointeur vers le joueur
    void setPlayer(Player* player);

    sf::Vector2u getArenaSize() const;

    /// @brief ajoute un ennemi à la liste des ennemis
    /// @param enemy pointeur unique vers l'ennemi
    void addEnemy(std::unique_ptr<Enemy> enemy);

    /// @brief ajoute une attaque du joueur à la liste des attaques du joueur
    /// @param playerAttack pointeur unique vers l'attaque du joueur
    void addPlayerAttack(std::unique_ptr<Attack> playerAttack);

    /// @brief ajoute une attaque d'un ennemi à la liste des attaques des ennemis
    /// @param enemyAttack pointeur unique vers l'attaque de l'ennemi
    void addEnemyAttack(std::unique_ptr<Attack> enemyAttack);

    /// @brief ajoute une animation à la liste des animations
    /// @param animation pointeur unique vers l'animation
    void addAnimation(std::unique_ptr<Animation> animation);

    /// @brief ajoute une onomatopée à la liste des onomatopées
    /// @param onomatope pointeur unique vers l'onomatopée
    void addOnomatope(std::unique_ptr<Onomatope> onomatope);

    void addItem(std::unique_ptr<Item> item);

    /// @brief fait apparaitre un kamikaze
    /// @param position position d'apparition
    void spawnKamikaze(sf::Vector2f position);

    void spawnRocketShip();

    void spawnShieldShip();

    /// @brief dessine toutes les entités & autres
    void draw() const;

    /// @brief applique les collisions entre les entités
    void collide();

    /// @brief met à jour toutes les entités & autres
    /// @param dt delta time
    /// @param mousePosition position de la souris
    void update(float dt, sf::Vector2i mousePosition);

    /// @brief ~EntityManager est le destructeur de EntityManager
    ~GameObjectManager();
};
