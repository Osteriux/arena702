/// @file enemyFactory.h
/// @brief Déclaration de la classe EnemyFactory pour la création des ennemis dans le jeu.
/// 
/// La classe EnemyFactory est responsable de la création des différents types d'ennemis
/// telles que les ennemis basiques, les ennemis suicides, les ennemis forts et les tanks.
/// Elle fournit une méthode statique pour créer un ennemi en fonction du type spécifié.

#pragma once
#include "../display/score.h"
#include "../../entitys/enemies/enemy.h"
#include "../../entitys/enemies/kamikaze.h"
#include "../../entitys/enemies/elite.h"
#include "../../entitys/enemies/bosses/rocketShip.h"
#include "../../entitys/enemies/bosses/shieldShip.h"
#include "weaponFactory.h"

/// @brief Fabrique construisant les différents types d'ennemis. <br/>
/// La classe EnemyFactory est responsable de la création des différents types d'ennemis
/// telles que les ennemis basiques, les ennemis suicides, les ennemis forts et les tanks.
/// Elle fournit une méthode statique pour créer un ennemi en fonction du type spécifié.
class EnemyFactory
{
private:
    /// @brief pointeur vers le score
    Score* score;

    /// @brief niveau du jeu
    int gameStage = 0;

public:
    /// @brief Constructeur de EnemyFactory
    /// @param score pointeur vers le score
    EnemyFactory(Score* score);

    /// @brief change le niveau du jeu
    void setGameStage(int stage);

    /// @brief Enum des différents types d'ennemis.
    enum class EnemyType
    {
        Basic,
        Elite,
        Kamikaze,
        Rocket,
        Shield
    };

    /// @brief Crée un ennemi du type spécifié.
    /// @param type Le type d'ennemi à créer.
    /// @param weapon Le type d'arme que l'ennemi utilisera.
    /// @param entityManager Pointeur vers le gestionnaire d'entités.
    /// @param windowSize La taille de la fenêtre de jeu.
    /// @param position La position initiale de l'ennemi.
    /// @return Un pointeur unique vers l'ennemi créé.
    std::unique_ptr<Enemy> createEnemy(EnemyType type, WeaponFactory::WeaponType weapon, GameObjectManager* entityManager, sf::Vector2u windowSize, sf::Vector2f position);

    /// @brief Obtient le chemin de la texture pour le type d'ennemi spécifié.
    /// @param type Le type d'ennemi.
    /// @return Le chemin de la texture sous forme de chaîne de caractères.
    static std::string texturePath(EnemyType type);
};
