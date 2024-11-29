/// @file customRandom.h
/// @brief Déclaration de la classe CustomRandom pour la génération de nombres aléatoires dans le jeu.
///
/// La classe CustomRandom est responsable de la génération de nombres aléatoires
/// utilisés pour déterminer la position d'apparition des ennemis, ainsi que pour
/// décider si un ennemi doit apparaître ou non. Elle utilise des distributions
/// aléatoires pour fournir ces valeurs et maintient la taille de l'arène pour
/// générer des positions valides.

#pragma once
#include <random>
#include <SFML/Graphics.hpp>

/// @brief classe permettant de générer des nombres aléatoires. <br/>
/// La classe CustomRandom est responsable de la génération de nombres aléatoires
/// utilisés pour déterminer la position d'apparition des ennemis, ainsi que pour
/// décider si un ennemi doit apparaître ou non. Elle utilise des distributions
/// aléatoires pour fournir ces valeurs et maintient la taille de l'arène pour
/// générer des positions valides.
class CustomRandom
{
private:
    /// @brief générateur de nombres aléatoires
    std::mt19937 gen;

    /// @brief distribution pour savoir si un ennemi doit apparaitre
    std::uniform_int_distribution<int> spawnDist;

    /// @brief distribution pour savoir si un ennemi doit être un élite
    std::uniform_int_distribution<int> eliteDist;

    /// @brief distribution pour savoir si un ennemi doit être un ennemi armée à distance
    std::uniform_int_distribution<int> rangedDist;

    /// @brief distribution pour savoir de quel côté de l'arène l'ennemi doit apparaitre
    std::uniform_int_distribution<int> sideDist;

    /// @brief distribution des coordonnées x et y d'apparition des ennemi
    std::uniform_real_distribution<float> posDist;

    /// @brief distribution pour savoir si un item doit apparaitre
    std::uniform_int_distribution<int> spawnItemDist;

    /// @brief distribution des coordonnées x d'apparition des items
    std::uniform_real_distribution<float> itemXDist;

    /// @brief distribution des coordonnées y d'apparition des items
    std::uniform_real_distribution<float> itemYDist;

    /// @brief taille de l'arène
    sf::Vector2u arenaSize;
public:
    /// @brief Constructeur par défault de CustomRandom
    CustomRandom() = default;
    /// @brief Constructeur de CustomRandom
    /// @param arenaSize taille de l'arène
    CustomRandom(sf::Vector2u arenaSize);

    /// @brief génère une position aléatoire
    /// @return une position aléatoire
    sf::Vector2f getRandomPosition();

    /// @brief génère une position aléatoire pour un boss
    /// @return une position aléatoire pour un boss
    sf::Vector2f getRandomBossPosition();

    /// @brief génère une position aléatoire pour un item
    /// @return une position aléatoire pour un item
    sf::Vector2f getRandomItemPosition();

    /// @brief génère un booléen aléatoire pour savoir si un item doit apparaitre
    /// @return si un item doit apparaitre
    bool doSpawnItem();

    /// @brief génère un booléen aléatoire pour savoir si un ennemi doit apparaitre
    /// @return si un ennemi doit apparaitre
    bool doSpawnEnemy();

    /// @brief génère un booléen aléatoire pour savoir si un ennemi doit être un élite
    /// @return si un ennemi doit être un élite
    bool isEnemyElite();

    /// @brief génère un booléen aléatoire pour savoir si un ennemi est un ennemi armée à distance
    /// @return si un ennemi est un ennemi armée à distance
    bool isEnemyRanged();

    /// @brief ~CustomRandom est le destructeur par default de CustomRandom
    ~CustomRandom() = default;
};