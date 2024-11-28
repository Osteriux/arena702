/// @file slash.h
/// @brief Déclaration de la classe Slash pour représenter une attaque au corps à corps dans le jeu.
///
/// La classe Slash hérite de la classe Attack et représente une attaque au corps à corps.
/// Elle permet de définir les propriétés spécifiques à une attaque de type slash, telles que
/// les dégâts, la durée de vie, et la couleur de l'attaque. Elle fournit également des méthodes
/// pour gérer les collisions avec d'autres entités et mettre à jour l'état de l'attaque en fonction
/// du temps écoulé.

#pragma once
#include "attack.h"
#include "../../entitys/entity.h"

/// @brief représente une attaque au corps à corps. <br/>
/// La classe Slash hérite de la classe Attack et représente une attaque au corps à corps.
/// Elle permet de définir les propriétés spécifiques à une attaque de type slash, telles que
/// les dégâts, la durée de vie, et la couleur de l'attaque. Elle fournit également des méthodes
/// pour gérer les collisions avec d'autres entités et mettre à jour l'état de l'attaque en fonction
/// du temps écoulé.
class Slash : public Attack
{
public:
    /// @brief Constructeur de Slash
    /// @param damage dégâts causés par le slash
    /// @param duration durée de vie du slash
    /// @param owner entité qui a lancé le slash
    /// @param color couleur du slash
    Slash(int damage, float duration, Entity* owner, sf::Color color);

    /// @brief appelé lorsqu'un slash entre en collision avec une entité
    /// @param entity entité avec laquelle le slash est entré en collision
    void onCollision(Entity* entity) override;

    /// @brief met à jour le slash en fonction du temps écoulé
    /// @param dt delta time
    /// @return si le slash est toujours en vie
    bool update(float dt) override;

    /// @brief ~Slash est le destructeur par default de Slash
    ~Slash() = default;
};
