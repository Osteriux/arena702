#pragma once
#include <memory>
#include "../../pickups/item.h"
#include "../../pickups/bonus/healBall.h"

class ItemFactory
{
public:
    enum class ItemType
    {
        HealBall
    };
    static std::unique_ptr<Item> createItem(ItemType type, sf::Vector2f position);
private:
    static std::string getItemTexturePath(ItemType type);
};

