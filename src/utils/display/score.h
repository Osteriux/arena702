/// @file score.h
/// @brief Déclaration de la classe Score pour la gestion du score du joueur.
///
/// La classe Score est responsable de la gestion du score du joueur.
/// Elle permet d'ajouter des points au score actuel et de récupérer le score actuel.

#pragma once
#include <memory>
#include "../../animations/stageChange.h"

class EnemyFactory;
class GameObjectManager;

/// @brief gère le score du joueur. <br/>
/// La classe Score est responsable de la gestion du score du joueur.
/// Elle permet d'ajouter des points au score actuel et de récupérer le score actuel.
class Score
{
private:
    /// @brief score du joueur
    unsigned long int score;

    /// @brief pointeur vers EnemyFactory pour notifier du stage actuel
    EnemyFactory* enemyFactory;

    /// @brief pointeur vers GameObjectManager pour faire apparaitre les bosses
    GameObjectManager* gameObjectManager;

    /// @brief stage actuel du jeu
    int stage;

    /// différrents stages du jeux :
    /// @brief debut du jeu
    static const unsigned long int STAGE_1 = 1000;

    /// @brief milieu du jeu
    static const unsigned long int STAGE_2 = 4000;

    /// @brief 1er boss
    static const unsigned long int STAGE_3 = 8000;

    /// @brief après le 1er boss
    static const unsigned long int STAGE_4 = 15000;

    /// @brief 2eme boss
    static const unsigned long int STAGE_5 = 20000;

    /// @brief après le 2eme boss
    static const unsigned long int STAGE_6 = 30000;

    /// @brief double boss
    static const unsigned long int STAGE_7 = 50000;

    /// @brief vérifie le stage du jeu
    /// @details notifie l'EnemyFactory du stage actuel
    void checkStage();

public:
    /// @brief Constructeur de Score
    Score();

    /// @brief passe une référence de EnemyFactory à Score
    /// @param enemyFactory pointeur vers EnemyFactory
    void setEnemyFactory(EnemyFactory* enemyFactory);

    void setGameObjectManager(GameObjectManager* gameObjectManager);

    /// @brief getteur du score
    /// @return le score du joueur
    unsigned int getScore() const;

    /// @brief calcule le nombre d'ennemis maximum autorisé en fonction du stage actuel
    /// @return le nombre d'ennemis maximum
    int getEnemyCap() const;

    /// @brief ajoute un score au score actuel
    /// @param score score à ajouter
    void addScore(unsigned int score);

    /// @brief reset le score
    void reset();

    /// @brief Destructeur par défaut de Score
    ~Score() = default;
};
