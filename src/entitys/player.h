/// @file player.h
/// @brief Déclaration de la classe Player représentant le joueur dans le jeu.
///
/// La classe Player est responsable de la gestion du joueur dans le jeu.
/// Elle maintient un pointeur vers un objet GameObjectManager pour interagir avec les entités.

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"
#include "../weapons/gun.h"
#include "../animations/onomatope.h"

class GameObjectManager;

/// @brief représente le joueur. <br/>
/// La classe Player est responsable de la gestion du joueur dans le jeu.
/// Elle maintient un pointeur vers un objet GameObjectManager pour interagir avec les entités.
class Player : public Entity
{
    private:
        /// @brief indique si le joueur est en train d'attaquer
        bool attacking;

        /// @brief dégâts de l'arme du joueur
        int weaponDamage;

        /// @brief indique si le joueur est mort et notifi la boucle principale
        bool* isGameOver;
    public:
        /// @brief Constructeur de Player
        /// @param gameObjectManager pointeur vers l'GameObjectManager
        /// @param windowSize taille de la fenêtre
        /// @param isGameOver pointeur vers l'indicateur de fin de jeu
        Player(GameObjectManager* gameObjectManager, sf::Vector2u windowSize, bool* isGameOver);

        /// @brief setteur de l'attaque du joueur
        /// @param attacking si le joueur est en train d'attaquer
        void setAttacking(bool attacking);

        /// @brief setteur de l'indicateur de déplacement du joueur <br/>
        /// a la particularité de lentement agmenter la valeur au dela de 1
        /// pour donner un meilleur effet de déplacement au joueur 
        /// @param moving indicateur de déplacement
        void setMoving(float moving) override;

        void upgradeWeapon(int damage);

        /// @brief met à jour le joueur
        /// @param dt delta time
        /// @param mousePosition position de la souris
        bool update(float dt, sf::Vector2f mousePosition) override;

        /// @brief appelé lorsqu'une entité entre en collision avec le joueur
        /// @param entity entité avec laquelle le joueur est entré en collision
        void onCollision(Entity* entity) override;

        /// @brief déclenche l'attaque du joueur
        void attack() override;

        /// @brief déclenche le dash du joueur
        /// @warning non implémenté
        void dash();

        /// @brief inflige des dégâts au joueur
        /// @param damage dégâts infligés
        void takeDamage(int damage) override;

        /// @brief soigne le joueur
        /// @param heal points de vie rendus
        virtual void heal(int heal) override;

        /// @brief appelé lors de la mort du joueur
        void onDeath() override;

        /// @brief reset le joueur
        void reset();

        /// @brief ~Player est le destructeur par default de Player
        ~Player() = default;

        /// @brief affiche les informations du joueur
        /// @warning utilisé pour le debug
        void debug();
};
