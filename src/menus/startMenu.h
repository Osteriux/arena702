/// @file startMenu.h
/// @brief Déclaration de la classe StartMenu pour la gestion du menu de démarrage dans l'application.
///
/// La classe StartMenu hérite de la classe abstraite Menu et permet de gérer le menu de démarrage.
/// Elle gère les propriétés spécifiques au menu de démarrage telles que le titre, les options pour démarrer
/// ou quitter le jeu, ainsi que les indicateurs de démarrage et de fin du jeu. Elle fournit également des
/// méthodes pour dessiner le menu à l'écran et gérer les entrées clavier.

#pragma once
#include "menu.h"

/// @brief gère le menu de démarrage. <br/>
/// La classe StartMenu hérite de la classe abstraite Menu et permet de gérer le menu de démarrage.
/// Elle gère les propriétés spécifiques au menu de démarrage telles que le titre, les options pour démarrer
/// ou quitter le jeu, ainsi que les indicateurs de démarrage et de fin du jeu. Elle fournit également des
/// méthodes pour dessiner le menu à l'écran et gérer les entrées clavier.
class StartMenu : public Menu
{
private:
    /// @brief titre du menu de démarrage
    sf::Text title;

    /// @brief texte pour démarrer le jeu
    sf::Text start;

    /// @brief texte pour quitter le jeu
    sf::Text exit;

    /// @brief indicateur de démarrage du jeu
    bool* isGameStarted;

    /// @brief indicateur de fin du jeu
    bool* isGameExit;

public:
    /// @brief Constructeur de StartMenu
    /// @param window fenêtre où dessiner le menu
    /// @param windowSize taille de la fenêtre
    /// @param isGameStarted pointeur vers l'indicateur de démarrage du jeu
    /// @param isGameExit pointeur vers l'indicateur de fin du jeu
    StartMenu(sf::RenderWindow* window, sf::Vector2u windowSize, bool* isGameStarted, bool* isGameExit);

    void draw() const override;

    void handleInput(sf::Keyboard::Key key, bool isPressed) override;

    /// @brief ~StartMenu est le destructeur par default de StartMenu
    ~StartMenu() = default;
};
