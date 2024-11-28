/// @file elite.h
/// @brief Déclaration de la classe Elite pour représenter un ennemi élite dans le jeu.
///
/// La classe Elite hérite de la classe Enemy et représente un type d'ennemi plus puissant.
/// Elle possède des attributs spécifiques tels que la taille, la santé, l'arme, la vitesse,
/// le chemin de la texture, le gestionnaire d'entités, la position et le score.
/// La méthode onDeath est appelée lors de la mort de l'ennemi pour ajouter des points au score
/// et faire apparaître un kamikaze.

#pragma once
#include "enemy.h"

/// @brief représente un ennemi élite. <br/>
/// La classe Elite hérite de la classe Enemy et représente un type d'ennemi plus puissant.
/// Elle possède des attributs spécifiques tels que la taille, la santé, l'arme, la vitesse,
/// le chemin de la texture, le gestionnaire d'entités, la position et le score.
/// La méthode onDeath est appelée lors de la mort de l'ennemi pour ajouter des points au score
/// et faire apparaître un kamikaze.
class Elite : public Enemy
{
public:
    Elite (float size, int health, Weapon* weapon, float speed, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score);
    
    void takeDamage(int damage) override;

    /// @brief appelé lors de la mort de l'ennemi
    /// @details ajoute 100 points au score et fait apparaitre un kamikaze
    void onDeath() override;

    /// @brief ~Elite est le destructeur par default d'Elite
    ~Elite() = default;
};
