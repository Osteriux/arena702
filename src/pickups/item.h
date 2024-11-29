/// @file item.h
/// @brief Déclaration de la classe Item pour la gestion des items ramassables dans l'application.
///
/// La classe Item est une classe abstraite qui représente un item que'une entité peut ramasser. Elle hérite de
/// sf::Sprite et gère les propriétés de l'item telles que la texture, l'état de ramassage et le temps de vie.
/// Elle fournit également des méthodes pour gérer le ramassage de l'item et mettre à jour son état en fonction
/// du temps écoulé.

#pragma once
#include <SFML/Graphics.hpp>
#include "../entitys/entity.h"

/// @brief class abstraite qui représente un item que le joueur peut ramasser. <br/>
/// La classe Item est une classe abstraite qui représente un item que'une entité peut ramasser. Elle hérite de
/// sf::Sprite et gère les propriétés de l'item telles que la texture, l'état de ramassage et le temps de vie.
/// Elle fournit également des méthodes pour gérer le ramassage de l'item et mettre à jour son état en fonction
/// du temps écoulé.
class Item : public sf::Sprite
{
protected:
    /// @brief texture de l'item
    sf::Texture texture;

    /// @brief indique si l'item a été ramassé
    bool isPickedUp;

    /// @brief temps que l'item restera affiché
    float timeToLive;
public:
    /// @brief Constructeur d'Item
    /// @param texturePath chemin vers la texture de l'item
    /// @param position position de l'item
    /// @param timeToLive temps que l'item restera affiché
    Item(std::string texturePath, sf::Vector2f position, float timeToLive);

    /// @brief appelé lorsque l'item est ramassé l'item
    /// @param e entité qui a ramassé l'item
    virtual void onPickup(Entity* e) = 0;

    /// @brief met à jour l'item en fonction du temps écoulé
    /// @param dt delta time
    /// @return si l'item est toujours affiché
    virtual bool update(float dt);

    /// @brief ~Item est le destructeur par default de Item
    ~Item() = default;
};
