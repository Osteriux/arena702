/// @file onomatope.h
/// @brief Déclaration de la classe Onomatope pour la gestion des textes temporaires à l'écran.
///
/// La classe Onomatope permet d'afficher un texte à l'écran pendant une durée déterminée.
/// Elle gère les propriétés du texte telles que le contenu, la couleur, la position, la durée d'affichage,
/// et la taille. Elle fournit également des méthodes pour dessiner le texte à l'écran et mettre à jour
/// son état en fonction du temps écoulé.

#pragma once
#include <SFML/Graphics.hpp>

/// @brief gére un texte qui s'affiche à l'écran pendant un certain temps. <br/>
/// La classe Onomatope permet d'afficher un texte à l'écran pendant une durée déterminée.
/// Elle gère les propriétés du texte telles que le contenu, la couleur, la position, la durée d'affichage,
/// et la taille. Elle fournit également des méthodes pour dessiner le texte à l'écran et mettre à jour
/// son état en fonction du temps écoulé.
class Onomatope
{
protected:
    /// @brief texte qui sera affiché
    sf::Text text;

    /// @brief police d'écriture du texte
    sf::Font font;

    /// @brief temps que le texte restera affiché
    float duration;
public:
    /// @brief Constructeur d'Onomatope
    /// @param text texte à afficher
    /// @param color couleur du texte
    /// @param position position du texte
    /// @param duration temps que le texte restera affiché
    /// @param size taille du texte (par défaut 20)
    Onomatope(std::string text, sf::Color color, sf::Vector2f position, float duration, int size = 20);

    /// @brief dessine le texte à l'écran
    /// @param window fenêtre où dessiner le texte
    void draw(sf::RenderWindow* window) const;

    /// @brief met à jour le texte en fonction du temps écoulé
    /// @param dt delta time
    virtual bool update(float dt);

    /// @brief ~Onomatope est le destructeur par default d'Onomatope
    ~Onomatope() = default;
};
