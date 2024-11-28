/// @file attack.h
/// @brief Déclaration de la classe Attack pour la gestion des attaques dans le jeu.
/// 
/// La classe Attack est une classe abstraite qui permet de gérer les différentes
/// attaques disponibles dans le jeu. Elle définit les propriétés communes à toutes
/// les attaques telles que les dégâts, la vitesse, la durée de vie, et la texture.
/// Elle fournit également des méthodes pour gérer les collisions, mettre à jour l'état
/// de l'attaque en fonction du temps écoulé, et un constructeur pour initialiser les propriétés
/// de l'attaque.

#pragma once
#include <SFML/Graphics.hpp>

class Entity;

/// @brief classe abstraite qui permet de gérer une attaque. <br/>
/// La classe Attack est une classe abstraite qui permet de gérer les différentes
/// attaques disponibles dans le jeu. Elle définit les propriétés communes à toutes
/// les attaques telles que les dégâts, la vitesse, la durée de vie, et la texture.
/// Elle fournit également des méthodes pour gérer les collisions, mettre à jour l'état
/// de l'attaque en fonction du temps écoulé, et un constructeur pour initialiser les propriétés
/// de l'attaque.
class Attack : public sf::Sprite
{
protected:
    /// @brief texture de l'attaque
    sf::Texture texture;

    /// @brief entité qui a lancé l'attaque
    Entity* owner;

    /// @brief dégâts causés par l'attaque
    float damage;

    /// @brief vitesse de déplacement de l'attaque
    float speed;

    /// @brief durée de vie de l'attaque
    float duration;
public:
    /// @brief Constructeur d'Attack
    /// @param owner entité qui a lancé l'attaque
    /// @param damage dégâts causés par l'attaque
    /// @param speed vitesse de déplacement de l'attaque
    /// @param duration durée de vie
    /// @param color couleur de l'attaque
    /// @warning Attack est une classe abstraite, il n'est pas possible de créer une instance de cette classe
    Attack(Entity* owner, float damage, float speed, float duration, sf::Color color);

    virtual bool collidesWith(const sf::FloatRect &rectangle);

    /// @brief appelé lorsqu'une attaque entre en collision avec une entité
    /// @param entity 
    virtual void onCollision(Entity* entity) = 0;

    /// @brief met à jour l'attaque en fonction du temps écoulé
    /// @param dt delta time
    virtual bool update(float dt);

    /// @brief ~Attack est le destructeur par default d'Attack
    virtual ~Attack() = default;
};
