/// @file weaponFactory.h
/// @brief Déclaration de la classe WeaponFactory pour la création des armes dans le jeu.
/// 
/// La classe WeaponFactory est responsable de la création des différents types d'armes
/// telles que les armes de combat rapproché, les armes à projectiles et les lasers.
/// Elle fournit une méthode statique pour créer une arme en fonction du type spécifié.

#pragma once
#include "../../weapons/weapon.h"
#include "../../weapons/closeCombat.h"
#include "../../weapons/gun.h"
#include "../../weapons/laserGun.h"

/// @brief Fabrique statique construisant les différents types d'armes. <br/>
/// La classe WeaponFactory est responsable de la création des différents types d'armes
/// telles que les armes de combat rapproché, les armes à projectiles et les lasers.
/// Elle fournit une méthode statique pour créer une arme en fonction du type spécifié.
class WeaponFactory
{
public:
    /// @brief Enum des différents types d'armes.
    enum class WeaponType
    {
        CLoseCombat,
        Projectile,
        Laser
    };

    /// @brief Crée une arme du type spécifié.
    /// @param type Le type d'arme à créer.
    /// @param damage Les dégâts causés par l'arme.
    /// @param cooldown Le temps entre chaque attaque.
    /// @param color La couleur de l'attaque.
    static Weapon* createWeapon(WeaponType type, int damage, float cooldown, sf::Color color);
};