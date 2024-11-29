/// @file laserGun.h
/// @brief Déclaration de la classe LaserGun pour la gestion des pistolets laser dans l'application.
///
/// La classe LaserGun hérite de la classe Weapon et représente une arme de type pistolet laser.
/// Elle gère les propriétés spécifiques du pistolet laser telles que les dégâts, la durée de vie, le cooldown,
/// la couleur de l'attaque et l'offset de l'attaque. Elle fournit également des méthodes pour gérer l'attaque,
/// le réglage de l'offset et la réinitialisation du cooldown.

#pragma once
#include "weapon.h"
#include "attacks/laser.h"

/// @brief classe qui représente un pistolet laser. <br/>
/// La classe LaserGun hérite de la classe Weapon et représente une arme de type pistolet laser.
/// Elle gère les propriétés spécifiques du pistolet laser telles que les dégâts, la durée de vie, le cooldown,
/// la couleur de l'attaque et l'offset de l'attaque. Elle fournit également des méthodes pour gérer l'attaque,
/// le réglage de l'offset et la réinitialisation du cooldown.
class LaserGun : public Weapon
{
private:
    /// @brief offset de l'attaque
    float offset;
public:
    /// @brief Constructeur de LaserGun
    /// @param damage dégâts causés par l'arme
    /// @param duration durée de vie
    /// @param cooldown temps entre chaque attaque
    /// @param color couleur de l'att
    LaserGun(int damage, float duration, float cooldown, sf::Color color);

    /// @brief setteur de l'offset de l'arme
    /// @param offset offset de l'arme
    void setOffset(float offset) override;

    /// @brief reset le cooldown de l'arme
    void resetCooldown() override;

    std::unique_ptr<Attack> attack(Entity* owner) override;

    /// @brief ~LaserGun est le destructeur par default de LaserGun
    ~LaserGun() = default;
};
