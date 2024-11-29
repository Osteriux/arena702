/// @file healBall.h
/// @brief Déclaration de la classe HealBall pour la gestion des items de soin dans l'application.
///
/// La classe HealBall représente un item qui redonne de la vie à une entité lorsqu'il est ramassé.
/// Elle hérite de la classe abstraite Item et gère les propriétés spécifiques à l'item de soin telles que
/// l'animation de montée et de descente, la texture, et l'état de ramassage.

#pragma once
#include "../item.h"
#include <cmath>
#include <SFML/Graphics.hpp>

/// @brief représente un item qui redonne de la vie. <br/>
/// La classe HealBall représente un item qui redonne de la vie à une entité lorsqu'il est ramassé.
/// Elle hérite de la classe abstraite Item et gère les propriétés spécifiques à l'item de soin telles que
/// l'animation de montée et de descente, la texture, et l'état de ramassage.
class HealBall : public Item
{
private:
    /// @brief temps écoulé depuis le début de l'animation
    float elapsedTime;

    /// @brief vitesse de montée et de descente de l'item
    float bobbingSpeed;

    /// @brief hauteur de montée et de descente de l'item
    float bobbingHeight;

    /// @brief position initiale de l'item
    sf::Vector2f initialPosition;
public:
    /// @brief Constructeur de HealBall
    /// @param texturePath chemin vers la texture de l'item
    /// @param position position de l'item
    /// @param timeToLive temps que l'item restera affiché
    HealBall(std::string texturePath, sf::Vector2f position, float timeToLive);

    /// @brief soigne l'entité qui a ramassé l'item
    /// @param e entité qui a ramassé l'item
    void onPickup(Entity* e) override;

    /// @brief met à jour l'item en fonction du temps écoulé
    /// @param dt delta time
    /// @return si l'item est toujours affiché
    /// @details fait monter et descendre l'item
    bool update(float dt) override;

    /// @brief ~HealBall est le destructeur par default de HealBall	
    ~HealBall() = default;
};
