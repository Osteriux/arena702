/// @file itemFactory.h
/// @brief Déclaration de la classe ItemFactory pour la gestion de la création des items dans l'application.
///
/// La classe ItemFactory est responsable de la création des différents types d'items ramassables dans l'application.
/// Elle fournit une méthode statique pour créer un item en fonction de son type et de sa position, ainsi qu'une
/// méthode privée pour obtenir le chemin de la texture de l'item en fonction de son type.

#pragma once
#include <memory>
#include "../../pickups/item.h"
#include "../../pickups/bonus/healBall.h"

/// @brief factory qui gère la création des items. <br/>
/// La classe ItemFactory est responsable de la création des différents types d'items ramassables dans l'application.
/// Elle fournit une méthode statique pour créer un item en fonction de son type et de sa position, ainsi qu'une
/// méthode privée pour obtenir le chemin de la texture de l'item en fonction de son type.
class ItemFactory
{
public:
    /// @brief Enum des différents type d'item
    enum class ItemType
    {
        HealBall
    };

    /// @brief Crée un item du type spécifié.
    /// @param type Le type d'item à créer.
    /// @param position La position de l'item.
    static std::unique_ptr<Item> createItem(ItemType type, sf::Vector2f position);
private:
    /// @brief Retourne le chemin vers la texture de l'item.
    /// @param type Le type de l'item.
    static std::string getItemTexturePath(ItemType type);
};

