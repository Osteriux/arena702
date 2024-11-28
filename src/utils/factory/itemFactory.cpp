#include "itemFactory.h"

std::unique_ptr<Item> ItemFactory::createItem(ItemType type, sf::Vector2f position)
{
    switch (type)
    {
    case ItemType::HealBall:
        return std::make_unique<HealBall>(getItemTexturePath(type), position, 10.0f);
    default:
        return std::make_unique<HealBall>(getItemTexturePath(type), position, 1.0f);
    }
}

std::string ItemFactory::getItemTexturePath(ItemType type)
{
    switch (type)
    {
    case ItemType::HealBall:
        return "assets/life.png";
    default:
        return "assets/life.png";
    }
}