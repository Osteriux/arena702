/// @file shieldShip.h
/// @brief Déclaration de la classe ShieldShip pour la gestion des boss dans l'application.
///
/// La classe ShieldShip hérite de la classe Boss et représente un boss qui attaque le joueur en se protégeant avec un des lasers.
/// Elle gère les propriétés du boss telles que l'état de la cible, la position, et les méthodes d'attaque et de déplacement.
/// Elle fournit également des méthodes pour orienter le boss, tenter une attaque, et mettre à jour l'état du boss.

#pragma once
#include "boss.h"

/// @brief boss qui attaque le joueur en se protégeant avec un des lasers. <br/>
/// La classe ShieldShip hérite de la classe Boss et représente un boss qui attaque le joueur en se protégeant avec un des lasers.
/// Elle gère les propriétés du boss telles que l'état de la cible, la position, et les méthodes d'attaque et de déplacement.
/// Elle fournit également des méthodes pour orienter le boss, tenter une attaque, et mettre à jour l'état du boss.
class ShieldShip : public Boss
{
private:
    /// @brief indique si le boss a atteint sa cible
    bool goalReached;

    /// @brief déplace la cible du boss
    /// @param dt delta time
    /// @details non implémenté car la cible est statique
    void moveTarget(float dt) override{};

    /// @brief tente d'attaquer le joueur
    /// @param playerPosition position du joueur
    /// @details uniquement possible si le boss a atteint sa cible
    void attemptAttack(sf::Vector2f playerPosition) override;

    /// @brief oriente le boss vers la cible
    /// @param target coordonnées de la cible
    /// @param dt delta time
    /// @details le boss tourne lentement une fois la cible atteinte
    void orientate(sf::Vector2f target, float dt) override;

    /// @brief fait rebondir le boss
    /// @param entity entité avec laquelle le boss est entré en collision
    /// @details non implémenté car le boss ne rebondit pas
    void bounceBack(Entity* entity) override{};
public:
    /// @brief Constructeur de ShieldShip
    /// @param size taille du boss (rayon du cercle)
    /// @param health points de vie du boss
    /// @param speed vitesse du boss
    /// @param weapon arme du boss
    /// @param texturePath chemin vers la texture du boss
    /// @param gameObjectManager pointeur vers l'GameObjectManager
    /// @param position position du boss
    /// @param score pointeur vers le score
    ShieldShip(float size, int health, float speed, Weapon* weapon, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score);

    /// @brief déclenche l'attaque du boss
    /// @details le boss attaque avec un des lasers
    void attack() override;

    /// @brief déplace le boss
    /// @param dt delta time
    /// @details le boss s'arrête une fois la cible atteinte
    void move(float dt) override;
    
    bool update(float dt, sf::Vector2f playerPosition) override;
    
    /// @brief ~ShieldShip est le destructeur par default de ShieldShip
    ~ShieldShip() = default;
};
