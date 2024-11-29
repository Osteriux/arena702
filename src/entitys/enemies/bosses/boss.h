/// @file boss.h
/// @brief Déclaration de la classe Boss pour la gestion des boss ennemis dans l'application.
///
/// La classe Boss est une classe abstraite dérivée de Enemy qui représente un boss dans le jeu.
/// Elle gère les propriétés spécifiques aux boss telles que la cible, la méthode de déplacement de la cible,
/// et les tentatives d'attaque. Elle fournit également des méthodes pour déclencher une attaque,
/// mettre à jour l'état du boss, et vérifier si le boss est toujours en vie.

#pragma once
#include "../enemy.h"

/// @brief classe abstraite qui représente un boss. <br/>
/// La classe Boss est une classe abstraite dérivée de Enemy qui représente un boss dans le jeu.
/// Elle gère les propriétés spécifiques aux boss telles que la cible, la méthode de déplacement de la cible,
/// et les tentatives d'attaque. Elle fournit également des méthodes pour déclencher une attaque,
/// mettre à jour l'état du boss, et vérifier si le boss est toujours en vie.
class Boss : public Enemy
{
protected:
    /// @brief cible du boss
    sf::Vector2f target;

    /// @brief déplace la cible du boss
    virtual void moveTarget(float dt) = 0;

    /// @brief tente d'attaquer le joueur
    virtual void attemptAttack(sf::Vector2f playerPosition) override = 0;
public:
    /// @brief Constructeur de Boss
    /// @param size taille du boss (rayon du cercle)
    /// @param health points de vie du boss
    /// @param weapon arme du boss
    /// @param speed vitesse du boss
    /// @param texturePath chemin vers la texture du boss
    /// @param gameObjectManager pointeur vers l'GameObjectManager
    /// @param position position du boss
    /// @param score pointeur vers le score
    Boss(float size, int health, Weapon* weapon, float speed, const std::string& texturePath, GameObjectManager* gameObjectManager, const sf::Vector2f& position, Score* score);

    /// @brief déclenche l'attaque du boss
    virtual void attack() override = 0;
    
    /// @brief met à jour le boss
    /// @param dt delta time
    /// @param playerPosition position du joueur 
    /// @return si le boss est toujours en vie
    virtual bool update(float dt, sf::Vector2f playerPosition) override = 0;

    /// @brief ~Boss est le destructeur par default de Boss
    ~Boss() = default;

};