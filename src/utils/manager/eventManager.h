/// @file eventManager.h
/// @brief Déclaration de la classe EventManager pour la gestion des évènements dans le jeu.
/// 
/// La classe EventManager est responsable de la gestion des différents évènements
/// tels que les pressions et relâchements de touches et de boutons de souris.
/// Elle maintient un pointeur vers un objet Player pour interagir avec le joueur.

#pragma once
#include <SFML/Graphics.hpp>
#include "../../entitys/player.h"

/// @brief gestionnaire des évènements. <br/>
/// La classe EventManager est responsable de la gestion des différents évènements
/// tels que les pressions et relâchements de touches et de boutons de souris.
/// Elle maintient un pointeur vers un objet Player pour interagir avec le joueur.
class EventManager
{
private:
    /// @brief pointeur vers le joueur
    Player* player;

    bool* isGamePaused;

    /// @brief gère l'évènement de pression d'une touche
    /// @param keyEvent évènement de la touche pressée
    void handleKeyDownEvent(sf::Event::KeyEvent keyEvent) const;

    /// @brief gère l'évènement de relachement d'une touche
    /// @param keyEvent évènement de la touche relachée
    void handleKeyUpEvent(sf::Event::KeyEvent keyEvent) const;

    /// @brief gère l'évènement de pression d'un bouton de la souris
    /// @param mouseButtonEvent évènement du bouton de la souris pressé
    void handleMouseDownEvent(sf::Event::MouseButtonEvent mouseButtonEvent) const;

    /// @brief gère l'évènement de relachement d'un bouton de la souris
    /// @param mouseButtonEvent évènement du bouton de la souris relaché
    void handleMouseUpEvent(sf::Event::MouseButtonEvent mouseButtonEvent) const;
public:
    /// @brief Constructeur de EventManager
    /// @param player pointeur vers le joueur
    EventManager(Player* player, bool* isGamePaused);

    /// @brief gère un évènement
    /// @param event évènement à gérer
    void handleEvent(sf::Event event) const;

    /// @brief ~EventManager est le destructeur par default de EventManager
    ~EventManager() = default;
};
