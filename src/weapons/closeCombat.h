/// @file closeCombat.h
/// @brief Déclaration de la classe CloseCombat pour la gestion des armes de corps à corps dans le jeu.
/// 
/// La classe CloseCombat hérite de la classe Weapon et représente une arme de corps à corps.
/// Elle permet de définir les propriétés spécifiques aux armes de corps à corps telles que les dégâts,
/// la durée de vie de l'attaque, le temps de recharge, et la couleur de l'attaque.
/// Elle fournit également une méthode pour lancer une attaque de type Slash.

#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "weapon.h"
#include "attacks/slash.h"

/// @brief représente une arme de corps à corps. <br/>
/// La classe CloseCombat hérite de la classe Weapon et représente une arme de corps à corps.
/// Elle permet de définir les propriétés spécifiques aux armes de corps à corps telles que les dégâts,
/// la durée de vie de l'attaque, le temps de recharge, et la couleur de l'attaque.
/// Elle fournit également une méthode pour lancer une attaque de type Slash.
class CloseCombat : public Weapon
{
    public:
        /// @brief Constructeur de CloseCombat
        /// @param damage dégâts causés par l'arme
        /// @param duration durée de vie de l'attaque
        /// @param cooldown temps entre chaque attaque
        /// @param color couleur de l'attaque
        CloseCombat(int damage, float duration, float cooldown, sf::Color color);

        /// @brief lance une attaque
        /// @param owner entité qui lance l'attaque
        /// @return un pointeur unique vers le Slash lancée
        std::unique_ptr<Attack> attack(Entity* owner) override;

        /// @brief ~CloseCombat est le destructeur par default de CloseCombat
        ~CloseCombat() = default;
};
