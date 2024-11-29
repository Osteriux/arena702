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
    /// @brief Constructeur d'Elite
    /// @param size taille de l'ennemi (rayon du cercle)
    /// @param health points de vie de l'ennemi
    /// @param weapon arme de l'ennemi
    /// @param speed vitesse de l'ennemi
    /// @param texturePath chemin vers la texture de l'ennemi
    /// @param gameObjectManager pointeur vers l'GameObjectManager
    /// @param position position de l'ennemi
    /// @param score pointeur vers le score
    Elite (float size, int health, Weapon* weapon, float speed, std::string texturePath, GameObjectManager* gameObjectManager, sf::Vector2f position, Score* score);
    
    void takeDamage(int damage) override;

    /// @brief appelé lors de la mort de l'ennemi
    /// @details ajoute 100 points au score et fait apparaitre un kamikaze
    void onDeath() override;

    /// @brief ~Elite est le destructeur par default d'Elite
    ~Elite() = default;
};
