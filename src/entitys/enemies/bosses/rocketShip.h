/// @file rocketShip.h
/// @brief Déclaration de la classe RocketShip, un boss qui attaque le joueur en faisant apparaître des Kamikaze.
///
/// La classe RocketShip hérite de la classe Boss et ajoute des fonctionnalités spécifiques
/// telles que la gestion du cooldown entre les attaques, la mise à jour de la position de la cible,
/// et la tentative d'attaque en fonction de la position du joueur.

#pragma once
#include "boss.h"

/// @brief boss qui attaque le foueur en faisant apparaitre des Kamikaze. <br/>
/// La classe RocketShip hérite de la classe Boss et ajoute des fonctionnalités spécifiques
/// telles que la gestion du cooldown entre les attaques, la mise à jour de la position de la cible,
/// et la tentative d'attaque en fonction de la position du joueur.
class RocketShip : public Boss
{
private:
    /// @brief temps entre chaque attaque
    float cooldown;

    /// @brief temps écoulé depuis la dernière attaque
    float currCooldown;

    /// @brief angle de rotation de la cible
    float angle;

    /// @brief rayon de la rotation de la cible
    float radius;

    /// @brief centre de l'orbite de la cible
    sf::Vector2f center;

    void moveTarget(float dt) override;

    void attemptAttack(sf::Vector2f playerPosition) override;
public:
    /// @brief Constructeur de RocketShip
    /// @param size taille du boss (rayon du cercle)
    /// @param health points de vie du boss
    /// @param speed vitesse du boss
    /// @param cooldown temps entre chaque attaque
    /// @param weapon arme du boss
    /// @param texturePath chemin vers la texture du boss
    /// @param gameObjectManager pointeur vers l'GameObjectManager
    /// @param position position du boss
    /// @param score pointeur vers le score
    RocketShip(float size, int health, float speed, float cooldown, Weapon* weapon, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score);

    /// @brief déclenche l'attaque du boss
    /// @details fait apparaitre des Kamikaze
    void attack() override;

    /// @brief met à jour le boss
    /// @param dt delta time
    /// @param playerPosition position du joueur
    /// @return si le boss est toujours en vie
    /// @details met à jour la position de la cible (rotation autour du centre de l'arène)
    bool update(float dt, sf::Vector2f playerPosition) override;

    /// @brief ~RocketShip est le destructeur par default de RocketShip
    ~RocketShip() = default;
};