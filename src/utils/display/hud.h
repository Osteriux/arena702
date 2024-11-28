/// @file hud.h
/// @brief Déclaration de la classe HUD pour l'affichage de l'interface utilisateur.
///
/// La classe HUD est responsable de l'affichage de l'interface utilisateur
/// tels que le nombre d'images par seconde, les points de vie du joueur et
/// la barre de vie du joueur.

#pragma once
#include <SFML/Graphics.hpp>
#include "score.h"
#include "../../entitys/player.h"

/// @brief représente l'interface utilisateur. <br/>
/// La classe HUD est responsable de l'affichage de l'interface utilisateur
/// tels que le nombre d'images par seconde, les points de vie du joueur et
/// la barre de vie du joueur.
class HUD
{
private:
    /// @brief pointeur vers la fenêtre
    sf::RenderWindow* window;

    /// @brief pointeur vers le joueur
    Player* player;

    /// @brief pointeur vers le score
    Score* score;

    /// @brief police d'écriture
    sf::Font font;

    /// @brief arrière plan de l'interface
    sf::RectangleShape background;

    /// @brief texte affichant le nombre d'image par seconde
    sf::Text textFps;

    /// @brief texte affichant les points de vie du joueur
    sf::Text textHealth;

    /// @brief barre de vie du joueur
    sf::RectangleShape healthBar;

    /// @brief texte affichant le score du joueur
    sf::Text textScore;
    
public:
    /// @brief Constructeur de HUD
    /// @param window pointeur vers la fenêtre
    /// @param player pointeur vers le joueur
    /// @param score pointeur vers le score
    HUD(sf::RenderWindow* window, Player* player, Score* score);

    /// @brief dessine l'interface utilisateur
    void draw() const;

    /// @brief met à jour l'interface utilisateur
    /// @param dt delta time
    void update(float dt);

    /// @brief ~HUD est le destructeur par default de HUD
    ~HUD() = default;
};