/// @file weapon.h
/// @brief Déclaration de la classe Weapon pour la gestion des armes dans le jeu.
/// 
/// La classe Weapon est une classe abstraite qui permet de gérer les différentes
/// armes disponibles dans le jeu. Elle définit les propriétés communes à toutes
/// les armes telles que les dégâts, la durée de vie, le temps de recharge, et la portée.
/// Elle fournit également des méthodes pour lancer une attaque, obtenir la portée de l'arme,
/// et mettre à jour l'état de l'arme en fonction du temps écoulé.

#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "attacks/attack.h"

/// @brief classe abstraite qui permet de gérer une arme. <br/>
/// La classe Weapon est une classe abstraite qui permet de gérer les différentes
/// armes disponibles dans le jeu. Elle définit les propriétés communes à toutes
/// les armes telles que les dégâts, la durée de vie, le temps de recharge, et la portée.
/// Elle fournit également des méthodes pour lancer une attaque, obtenir la portée de l'arme,
/// et mettre à jour l'état de l'arme en fonction du temps écoulé.
class Weapon
{
protected:
    /// @brief couleur de l'attaque
    sf::Color color;

    /// @brief dégâts causés par l'arme
    int damage;

    /// @brief durée de vie de l'attaque
    float duration;

    /// @brief temps entre chaque attaque
    float cooldown;

    /// @brief temps écoulé depuis la dernière attaque
    float currCooldown;

    /// @brief portée de l'arme
    int range;
public:
    /// @brief Constructeur de Weapon
    /// @param damage dégâts causés par l'arme
    /// @param duration durée de vie
    /// @param cooldown temps entre chaque attaque
    /// @param range portée de l'arme
    /// @param color couleur de l'att
    Weapon(int damage, float duration, float cooldown, int range, sf::Color color);

    /// @brief lance une attaque
    /// @param owner entité qui lance l'attaque
    /// @return un pointeur unique vers l'Attaque lancée
    virtual std::unique_ptr<Attack> attack (Entity* owner) = 0;

    /// @brief getteur de la portée de l'arme
    /// @return la portée de l'arme
    int getRange () const;

    virtual void setOffset(float offset){};

    virtual void resetCooldown(){};

    bool isReady() const;

    /// @brief met à jour l'arme en fonction du temps écoulé
    /// @param dt delta time    
    virtual void update(float dt);

    /// @brief ~Weapon est le destructeur par default de Weapon
    ~Weapon () = default;
};
