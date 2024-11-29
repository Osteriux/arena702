/// @file menu.h
/// @brief Déclaration de la classe Menu pour la gestion des menus dans l'application.
///
/// La classe Menu est une classe abstraite qui permet de gérer un menu. Elle gère les propriétés du menu
/// telles que le background, la fenêtre où dessiner le menu, et le font. Elle fournit également des méthodes
/// pour dessiner le menu à l'écran et gérer les entrées clavier.

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/// @brief classe abstraite qui permet de gérer un menu. <br/>
/// La classe Menu est une classe abstraite qui permet de gérer un menu. Elle gère les propriétés du menu
/// telles que le background, la fenêtre où dessiner le menu, et le font. Elle fournit également des méthodes
/// pour dessiner le menu à l'écran et gérer les entrées clavier.
class Menu : public sf::Sprite
{
protected:
    /// @brief background du menu
    sf::RectangleShape background;

    /// @brief fenêtre où dessiner le menu
    sf::RenderWindow* window;

    /// @brief font du menu
    sf::Font font;

public:
    /// @brief Constructeur de Menu
    /// @param window fenêtre où dessiner le menu
    /// @param windowSize taille de la fenêtre
    Menu(sf::RenderWindow* window, sf::Vector2u windowSize);

    /// @brief dessine le menu à l'écran
    virtual void draw() const;

    /// @brief gère les entrées clavier du menu
    /// @param key touche appuyée
    /// @param isPressed si la touche est appuyée
    virtual void handleInput(sf::Keyboard::Key key, bool isPressed) = 0;

    /// @brief met à jour le menu
    /// @details méthode virtuelle qui ne fait rien par default
    virtual void update(){};

    /// @brief ~Menu est le destructeur par default de Menu
    ~Menu() = default;
};
