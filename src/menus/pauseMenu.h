/// @file pauseMenu.h
/// @brief Déclaration de la classe PauseMenu pour la gestion du menu de pause dans l'application.
///
/// La classe PauseMenu hérite de la classe abstraite Menu et permet de gérer le menu de pause.
/// Elle gère les propriétés spécifiques au menu de pause telles que le titre, les options pour
/// reprendre ou quitter la partie, ainsi que les indicateurs de pause et de fin du jeu.
/// Elle fournit également des méthodes pour dessiner le menu à l'écran et gérer les entrées clavier.
#pragma once
#include "menu.h"

/// @brief gère le menu de pause. <br/>
/// La classe PauseMenu hérite de la classe abstraite Menu et permet de gérer le menu de pause.
/// Elle gère les propriétés spécifiques au menu de pause telles que le titre, les options pour
/// reprendre ou quitter la partie, ainsi que les indicateurs de pause et de fin du jeu.
/// Elle fournit également des méthodes pour dessiner le menu à l'écran et gérer les entrées clavier.
class PauseMenu : public Menu
{
private:
    /// @brief titre du menu pause
    sf::Text title;

    /// @brief texte pour reprendre la partie
    sf::Text resume;

    /// @brief texte pour quitter la partie
    sf::Text exit;

    /// @brief indicateur de la pause du jeu
    bool* isGamePaused;

    /// @brief indicateur de la fin du jeu
    bool* isGameExit;

public:
    /// @brief Constructeur de PauseMenu
    /// @param window fenêtre où dessiner le menu
    /// @param windowSize taille de la fenêtre
    /// @param isGamePaused pointeur vers l'indicateur de pause du jeu
    /// @param isGameExit pointeur vers l'indicateur de fin du jeu
    PauseMenu(sf::RenderWindow* window, sf::Vector2u windowSize, bool* isGamePaused, bool* isGameExit);

    void draw() const override;

    void handleInput(sf::Keyboard::Key key, bool isPressed) override;

    /// @brief ~PauseMenu est le destructeur par default de PauseMenu
    ~PauseMenu() = default;

};
