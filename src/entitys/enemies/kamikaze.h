/// @file kamikaze.h
/// @brief Déclaration de la classe Kamikaze pour la gestion des ennemis kamikazes dans le jeu.
///
/// La classe Kamikaze hérite de la classe Enemy et représente un ennemi spécial qui explose au contact du joueur.
/// Elle définit les propriétés spécifiques à ce type d'ennemi telles que la taille, les points de vie, la vitesse,
/// le chemin vers la texture, le gestionnaire d'entités et la position. Elle fournit également des méthodes pour
/// mettre à jour l'état de l'ennemi, gérer les collisions et les actions à effectuer lors de la mort de l'ennemi.

#pragma once
#include "enemy.h"

/// @brief représente un enemi speciale qui explose au contact du joueur. <br/>
/// La classe Kamikaze hérite de la classe Enemy et représente un ennemi spécial qui explose au contact du joueur.
/// Elle définit les propriétés spécifiques à ce type d'ennemi telles que la taille, les points de vie, la vitesse,
/// le chemin vers la texture, le gestionnaire d'entités et la position. Elle fournit également des méthodes pour
/// mettre à jour l'état de l'ennemi, gérer les collisions et les actions à effectuer lors de la mort de l'ennemi.
class Kamikaze : public Enemy
{
private:
    /// @brief dégâts infligés par l'ennemi
    int damage;
    
public:
    /// @brief Constructeur de Kamikaze
    /// @param size taille de l'ennemi (rayon du cercle)
    /// @param health points de vie de l'ennemi
    /// @param speed vitesse de l'ennemi
    /// @param damage dégâts infligés par l'ennemi
    /// @param texturePath chemin vers la texture de l'ennemi
    /// @param gameObjectManager pointeur vers l'GameObjectManager
    /// @param position position de l'ennemi
    /// @param score pointeur vers le score
    Kamikaze(float size, int health, float speed, int damage, Weapon* weapon, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score);

    /// @brief met à jour l'ennemi
    /// @param dt delta time
    /// @param playerPosition position du joueur
    /// @return si l'ennemi est toujours en vie
    bool update(float dt, sf::Vector2f playerPosition) override;

    /// @brief appelé lorsqu'un ennemi entre en collision avec un autre entité
    /// @brief si cette entité est le joueur, l'enemie explose
    /// @param entity entité avec laquelle l'ennemi est entré en collision
    void onCollision(Entity* entity) override;

    /// @brief ne fait rien cette enemie n'as pas d'arme
    void attack() override {};

    /// @brief  appelé lors de la mort de l'ennemi
    void onDeath() override;

    /// @brief ~Kamikaze est le destructeur par default de Kamikaze
    ~Kamikaze() = default;
};
