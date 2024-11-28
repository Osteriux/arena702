/// @file gun.h
/// @brief Déclaration de la classe Gun pour la gestion des armes à distance dans le jeu.
/// 
/// La classe Gun hérite de la classe abstraite Weapon et représente une arme à distance.
/// Elle définit des propriétés spécifiques aux armes à feu telles que la vitesse des balles
/// et le nombre de cibles que les balles peuvent traverser.
/// Elle fournit également une méthode pour lancer une attaque et obtenir un projectile.

#pragma once
#include "weapon.h"
#include "attacks/projectile.h"

/// @brief représente une arme à distance. <br/>
/// La classe Gun hérite de la classe abstraite Weapon et représente une arme à distance.
/// Elle définit des propriétés spécifiques aux armes à feu telles que la vitesse des balles
/// et le nombre de cibles que les balles peuvent traverser.
/// Elle fournit également une méthode pour lancer une attaque et obtenir un projectile.
class Gun : public Weapon
{
private:
    /// @brief vitesse des balles
    float bulletSpeed;

    /// @brief nombre de cible que les balles peuvent traverser
    int pierce;
public:
    /// @brief Constructeur de Gun
    /// @param damage dégâts causés par l'arme
    /// @param bulletSpeed vitesse des balles
    /// @param cooldown temps entre chaque attaque
    /// @param color couleur de l'attaque
    /// @param pierce nombre de cible que les balles peuvent traverser
    Gun(int damage, float bulletSpeed, float cooldown, sf::Color color, int pierce);

    /// @brief lance une attaque
    /// @param owner entité qui lance l'attaque
    /// @return un pointeur unique vers le Projectile lancée
    std::unique_ptr<Attack> attack(Entity* owner) override;

    /// @brief ~Gun est le destructeur par default de Gun
    ~Gun() = default;
};