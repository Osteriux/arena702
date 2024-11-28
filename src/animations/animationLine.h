/// @file animationLine.h
/// @brief Déclaration de la classe AnimationLine pour la gestion des animations dont les frames sont sur une ligne.
///
/// La classe AnimationLine permet de gérer une animation dont les frames sont disposées sur une seule ligne.
/// Elle gère les propriétés de l'animation telles que le nombre de frames, l'index de la frame actuelle, et fournit
/// des méthodes pour mettre à jour l'animation en fonction du temps écoulé.

#pragma once
#include <SFML/Graphics.hpp>
#include "animation.h"

/// @brief gére une animation dont les frames sontsur une ligne. <br/>
/// La classe AnimationLine permet de gérer une animation dont les frames sont disposées sur une seule ligne.
/// Elle gère les propriétés de l'animation telles que le nombre de frames, l'index de la frame actuelle, et fournit
/// des méthodes pour mettre à jour l'animation en fonction du temps écoulé.
class AnimationLine : public Animation
{
private:
    /// @brief le nombre de frames de l'animation
    int nbImages;

    /// @brief l'index de la frame actuel
    int currentImage;
public:
    /// @brief Constructeur d'AnimationLine
    /// @param texturePath chemin vers la texture de l'animation
    /// @param nbImages nombre de frames de l'animation
    /// @param rect taille d'une frame
    /// @param switchTime temps entre chaque frame
    /// @param position position de l'animation
    /// @param scale échelle de l'animation
    /// @warning Les frames de l'animation doivent être sur une seule ligne
    AnimationLine(const char* texturePath, int nbImages, sf::IntRect rect, float switchTime, sf::Vector2f position, sf::Vector2f scale);
    
    bool update(float dt) override;
    
    ~AnimationLine() = default;
};
