/// @file gameOver.h
/// @brief Déclaration de la classe GameOver pour la gestion du menu de fin de jeu.
///
/// La classe GameOver hérite de la classe abstraite Menu et permet de gérer le menu de fin de jeu.
/// Elle gère les propriétés du menu telles que le titre, les options de recommencer ou quitter le jeu,
/// et les indicateurs de sélection. Elle fournit également des méthodes pour dessiner le menu à l'écran
/// et gérer les entrées clavier.

#pragma once
#include "menu.h"
#include "../utils/display/score.h"

/// @brief gère le menu de GameOver. <br/>
/// La classe GameOver hérite de la classe abstraite Menu et permet de gérer le menu de fin de jeu.
/// Elle gère les propriétés du menu telles que le titre, les options de recommencer ou quitter le jeu,
/// et les indicateurs de sélection. Elle fournit également des méthodes pour dessiner le menu à l'écran
/// et gérer les entrées clavier.
class GameOver : public Menu
{
private:
    /// @brief score du joueur
    Score* score;

    /// @brief texte du score
    sf::Text scoreText;

    /// @brief titre du menu game over
    sf::Text title;

    /// @brief texte pour recommencer la partie
    sf::Text restart;

    /// @brief texte pour quitter la partie
    sf::Text exit;

    /// @brief indicateur de la sélection
    bool* isGameRestart;

    /// @brief indicateur de la sélection
    bool* isGameExit;
public:
    /// @brief Constructeur de GameOver
    /// @param window fenêtre où dessiner le menu
    /// @param windowSize taille de la fenêtre
    /// @param isGameRestart pointeur vers l'indicateur de recommencer la partie
    /// @param isGameExit pointeur vers l'indicateur de quitter la partie
    /// @param score score du joueur
    GameOver(sf::RenderWindow* window, sf::Vector2u windowSize, bool* isGameRestart, bool* isGameExit, Score* score);

    void draw() const override;

    /// @brief met à jour le menu
    /// @details met le score à jour
    void update() override;

    void handleInput(sf::Keyboard::Key key, bool isPressed) override;
    
    ~GameOver() = default;
};