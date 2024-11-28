/// @file enemyStatSupplier.h
/// @brief Déclaration de la classe EnemyStatSupplier pour fournir les statistiques des ennemis dans le jeu.
/// 
/// La classe EnemyStatSupplier est responsable de fournir les statistiques des différents types d'ennemis
/// en fonction du niveau de jeu. Elle contient des méthodes statiques pour obtenir les statistiques des
/// ennemis basiques, kamikazes, forts et tanks, ainsi qu'une méthode pour obtenir les statistiques d'un
/// ennemi en fonction de son type spécifié.

#pragma once
#include "../enemyFactory.h"

/// @brief Fournisseur de statistiques des ennemis. <br/>
/// La classe EnemyStatSupplier est responsable de fournir les statistiques des différents types d'ennemis
/// en fonction du niveau de jeu. Elle contient des méthodes statiques pour obtenir les statistiques des
/// ennemis basiques, kamikazes, forts et tanks, ainsi qu'une méthode pour obtenir les statistiques d'un
/// ennemi en fonction de son type spécifié.
class EnemyStatSupplier
{
private:
    /// @brief Obtient les statistiques de l'ennemi basique en fonction du niveau de jeu.
    /// @param gameStage Le niveau de jeu.
    /// @return Un tableau de flottants contenant les statistiques d'un enemy basic.
    static float* getBasicStat(int gameStage);

    /// @brief Obtient les statistiques de l'ennemi élite en fonction du niveau de jeu.
    /// @param gameStage Le niveau de jeu.
    /// @return Un tableau de flottants contenant les statistiques d'un enemy elite.
    static float* getEliteStat(int gameStage);

    /// @brief Obtient les statistiques de l'ennemi kamikaze en fonction du niveau de jeu.
    /// @param gameStage Le niveau de jeu.
    /// @return Un tableau de flottants contenant les statistiques d'un kamikaze.
    static float* getKamikazeStat(int gameStage);

    /// @brief Obtient les statistiques de l'ennemi fort en fonction du niveau de jeu.
    /// @param gameStage Le niveau de jeu.
    /// @return Un tableau de flottants contenant les statistiques du boss Rocket.
    static float* getRocketStat(int gameStage);

    /// @brief Obtient les statistiques de l'ennemi tank en fonction du niveau de jeu.
    /// @param gameStage Le niveau de jeu.
    /// @return Un tableau de flottants contenant les statistiques du boss Shield.
    static float* getShieldStat(int gameStage);

public:
    /// @brief Obtient les statistiques de l'ennemi spécifié en fonction du niveau de jeu.
    /// @param gameStage Le niveau de jeu.
    /// @param enemyType Le type d'ennemi.
    /// @return Un tableau de flottants contenant les statistiques de l'ennemi.
    /// @details Les statistiques sont dans l'ordre suivant : santé, vitesse, dégâts, cadence de tir.
    static float* getEnemyStat(int gameStage, EnemyFactory::EnemyType enemyType);
};
