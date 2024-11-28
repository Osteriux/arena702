/// @file entity.h
/// @brief Déclaration de la classe Entity pour la gestion des entités dans le jeu.
///
/// La classe Entity est une classe abstraite qui représente une entité dans le jeu.
/// Elle hérite de sf::Sprite et contient des attributs et des méthodes pour gérer
/// les propriétés et les comportements des entités, tels que la position, la vitesse,
/// la direction, la santé, les armes, les collisions, etc.

#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../weapons/weapon.h"

class GameObjectManager;

/// @brief classe abstraite qui permet de gérer une entité. <br/>
/// La classe Entity est une classe abstraite qui représente une entité dans le jeu.
/// Elle hérite de sf::Sprite et contient des attributs et des méthodes pour gérer
/// les propriétés et les comportements des entités, tels que la position, la vitesse,
/// la direction, la santé, les armes, les collisions, etc.
class Entity : public sf::Sprite
{
protected:
    /// @brief pointeur vers le GameObjectManager
    GameObjectManager* gameObjectManager;

    /// @brief texture de l'entité
    sf::Texture texture;

    /// @brief taille de la fenêtre
    sf::Vector2u windowSize;

    /// @brief vitesse de l'entité
    float speed;

    /// @brief vitesse maximale de l'entité
    float maxSpeed;

    /// @brief inquateur de déplacement de l'entité
    float moving;

    /// @brief vitesse de rotation de l'entité en degré par seconde
    int rotationSpeed;

    /// @brief direction de l'entité
    sf::Vector2f direction;

    /// @brief velocité de l'entité
    sf::Vector2f velocity;

    /// @brief accélération de l'entité
    sf::Vector2f acceleration;

    /// @brief points de vie de l'entité
    int health;

    /// @brief arme de l'entité
    Weapon* weapon;

    /// @brief temps d'invincibilité de l'entité
    float iframes;

    /// @brief temps écoulé depuis le dernier coup reçu
    float currIframes;

    /// @brief couleur des frames d'invincibilité
    sf::Color iFrameColor;

    /// @brief facteur de rebond de l'entité
    float bounceFactor;

    /// @brief taille de l'entité (rayon du cercle)
    float size;

    /// @brief oriente l'entité vers une cible
    /// @param target coordonnées de la cible
    /// @param dt delta time
    virtual void orientate(sf::Vector2f target, float dt);

    /// @brief met les frames d'invincibilité à jour
    void iFrames(float dt);

    /// @brief fait rebondir l'entité
    /// @param entity entité avec laquelle l'entité est entrée en collision
    virtual void bounceBack(Entity* entity); 
public:
    /// @brief Constructeur d'Entity
    /// @param size taille de l'entité (rayon du cercle)
    /// @param gameObjectManager pointeur vers l'GameObjectManager
    /// @param windowSize taille de la fenêtre
    /// @param x position x de l'entité
    /// @param y position y de l'entité
    /// @param speed vitesse de l'entité
    /// @param maxSpeed vitesse maximale de l'entité
    /// @param rotationSpeed vitesse de rotation de l'entité en degré par seconde
    /// @param health points de vie de l'entité
    /// @param weapon arme de l'entité
    /// @param iframes temps d'invincibilité de l'entité
    /// @param iFramesColor couleur des frames d'invincibilité
    /// @param bounceFactor facteur de rebond de l'entité
    Entity(float size, GameObjectManager* gameObjectManager, sf::Vector2u windowSize, float x, float y, float speed, float maxSpeed, int rotationSpeed, int health, Weapon* weapon, float iframes, sf::Color iFramesColor, float bounceFactor);

    /// @brief setteur du l'indicateur de déplacement de l'entité
    /// @param moving indicateur de déplacement
    virtual void setMoving(float moving);

    /// @brief getteur des points de vie de l'entité
    /// @return les points de vie de l'entité
    int getHealth() const;

    /// @brief getteur de la taille de l'entité
    /// @return la taille de l'entité
    float getSize() const;

    /// @brief getteur de la direction de l'entité
    /// @return la direction de l'entité
    sf::Vector2f getDirection() const;

    /// @brief getteur de la hitbox de l'entité
    /// @return la hitbox de l'entité
    sf::FloatRect getHitbox() const;

    /// @brief détection de collision avec une entité
    /// @param entity entité avec laquelle l'entité est potentiellement entrée en collision
    /// @return si l'entité est entrée en collision
    bool collidesWith(Entity* entity);
    
    /// @brief applique l'accélération à la vélocité
    void applyAcceleration();

    /// @brief déplace l'entité
    /// @param dt delta time
    virtual void move(float dt);
    
    /// @brief met à jour l'entité
    /// @param dt delta time
    /// @param target coordonnées de la cible
    virtual bool update(float dt, sf::Vector2f target) = 0;

    /// @brief appelé lorsqu'une entité entre en collision avec une autre entité
    /// @param entity entité avec laquelle l'entité est entrée en collision
    virtual void onCollision(Entity* entity) = 0;

    /// @brief déclenche l'attaque de l'entité
    virtual void attack() = 0;

    /// @brief inflige des dégâts à l'entité
    /// @param damage dégâts infligés
    virtual void takeDamage(int damage) = 0;

    virtual void heal(int heal) = 0;

    /// @brief appelé lors de la mort de l'entité
    virtual void onDeath() = 0;

    /// @brief ~Entity est le destructeur par default de Entity
    virtual ~Entity() {};
};
