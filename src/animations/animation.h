/// @file animation.h
/// @brief Déclaration de la classe Animation pour la gestion des animations.
///
/// La classe Animation permet de gérer une animation en utilisant une texture comprenant plusieurs frames.
/// Elle gère les propriétés de l'animation telles que la texture, le rectangle de la frame actuelle, le temps entre chaque frame,
/// et le temps écoulé depuis le dernier changement de frame. Elle fournit également des méthodes pour obtenir la texture courante
/// et mettre à jour l'animation en fonction du temps écoulé.

#pragma once
#include <SFML/Graphics.hpp>

/// @brief classe abstraite qui permet de gérer une animation. <br/>
/// La classe Animation permet de gérer une animation en utilisant une texture comprenant plusieurs frames.
/// Elle gère les propriétés de l'animation telles que la texture, le rectangle de la frame actuelle, le temps entre chaque frame,
/// et le temps écoulé depuis le dernier changement de frame. Elle fournit également des méthodes pour obtenir la texture courante
/// et mettre à jour l'animation en fonction du temps écoulé.
class Animation: public sf::Sprite
{
protected:
    /// @brief texture de l'animation comprennant toutes les frames
    sf::Texture texture;

    /// @brief rectangle de la texture qui correspond à la frame actuel
    sf::IntRect rect;

    /// @brief le temps entre chaque frame
    float switchTime;

    /// @brief le temps écoulé depuis le dernier changement de frame
    float currentTime;

public:
    /// @brief Constructeur d'Animation
    /// @param texturePath chemin vers la texture de l'animation
    /// @param rect taille d'une frame
    /// @param switchTime temps entre chaque frame
    /// @param position position de l'animation
    /// @param scale échelle de l'animation
    /// @warning Animation est une classe abstraite, il n'est pas possible de créer une instance de cette classe
    Animation(std::string texturePath, sf::IntRect rect, float switchTime, sf::Vector2f position, sf::Vector2f scale);

    /// @brief getteur de la texture courante de l'animation
    /// @return la texture de l'animation
    virtual sf::Texture getTexture() const;

    /// @brief met à jour l'animation en fonction du temps écoulé
    /// @param dt delta time
    virtual bool update(float dt) = 0;

    /// @brief destructeur par default d'Animation
    ~Animation() = default;
};