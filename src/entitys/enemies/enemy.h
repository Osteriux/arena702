/// @file enemy.h
/// @brief Déclaration de la classe Enemy pour la gestion des ennemis dans le jeu.
/// 
/// La classe Enemy représente un ennemi lambda dans le jeu. Elle hérite de la classe Entity
/// et fournit des propriétés et méthodes spécifiques aux ennemis, telles que la vitesse,
/// la tentative d'attaque, la mise à jour de l'état de l'ennemi, la gestion des collisions,
/// le déplacement, l'attaque, la prise de dégâts et la gestion de la mort de l'ennemi.

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../entity.h"
#include "../player.h"
#include "../../animations/animationLine.h"
#include "../../animations/onomatope.h"
#include "../../utils/display/score.h"

/// @brief représente un ennemi lambda. <br/>
/// La classe Enemy représente un ennemi lambda dans le jeu. Elle hérite de la classe Entity
/// et fournit des propriétés et méthodes spécifiques aux ennemis, telles que la vitesse,
/// la tentative d'attaque, la mise à jour de l'état de l'ennemi, la gestion des collisions,
/// le déplacement, l'attaque, la prise de dégâts et la gestion de la mort de l'ennemi.
class Enemy : public Entity
{
protected:
    /// @brief vitesse de déplacement de l'ennemi
    float speed;

    /// @brief pointeur vers le score
    Score* score;

    /// @brief tentative d'attaque si le joueur est à portée
    /// @param playerPosition position du joueur
    virtual void attemptAttack (sf::Vector2f playerPosition);

public:
    /// @brief Constructeur d'Enemy
    /// @param size taille de l'ennemi (rayon du cercle)
    /// @param health points de vie de l'ennemi
    /// @param weapon arme de l'ennemi
    /// @param speed vitesse de l'ennemi
    /// @param texturePath chemin vers la texture de l'ennemi
    /// @param gameObjectManager pointeur vers l'GameObjectManager
    /// @param position position de l'ennemi
    /// @param score pointeur vers le score
    Enemy (float size, int health, Weapon* weapon, float speed, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score);

    /// @brief met à jour l'ennemi
    /// @param dt delta time
    /// @param playerPosition position du joueur
    /// @return si l'ennemi est toujours en vie
    virtual bool update (float dt, sf::Vector2f playerPosition) override;

    /// @brief appelé lorsqu'un ennemi entre en collision avec un autre entité
    /// @param entity entité avec laquelle l'ennemi est entré en collision
    virtual void onCollision (Entity* entity) override;

    /// @brief déplace l'ennemi
    /// @param dt delta time
    void move (float dt) override;

    /// @brief déclenche l'attaque de l'ennemi
    virtual void attack () override;

    /// @brief inflige des dégâts à l'ennemi
    /// @param damage dégâts infligés
    virtual void takeDamage (int damage) override;

    virtual void heal(int heal) override{};

    /// @brief appelé lors de la mort de l'ennemi
    virtual void onDeath () override;

    /// @brief ~Enemy est le destructeur par default d'Enemy
    ~Enemy () = default;
};
