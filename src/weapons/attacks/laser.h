#pragma once
#include "attack.h"
#include "../../entitys/entity.h"

/// @brief représente une attaque de type laser. <br/>
class Laser : public Attack {
private:
    /// @brief portée de l'attaque
    float distance;

    /// @brief offset de l'attaque
    float offset;

    /// @brief détecte si une ligne intersecte un rectangle
    /// @param p1 début de la ligne
    /// @param p2 fin de la ligne
    /// @param rect rectangle
    /// @return si la ligne intersecte le rectangle
    bool lineIntersectsRect(sf::Vector2f p1, sf::Vector2f p2, sf::FloatRect rect) const;

    /// @brief détecte si une ligne intersecte une autre ligne
    /// @param p1 début de la première ligne
    /// @param p2 fin de la première ligne
    /// @param p3 début de la deuxième ligne
    /// @param p4 fin de la deuxième ligne
    /// @return si les lignes s'intersectent
    bool lineIntersectsLine(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f p4) const;
public:
    /// @brief Constructeur de Laser
    /// @param owner entité qui lance l'attaque
    /// @param damage dégâts causés par l'attaque
    /// @param duration durée de vie
    /// @param color couleur de l'attaque
    /// @param offset offset de l'attaque
    Laser(Entity* owner, float damage, float duration, sf::Color color, float offset);

    /// @brief detecte si l'attaue entre en collision avec une entité
    /// @param rectangle hitbox de l'entité
    /// @return si l'attaque entre en collision avec l'entité
    /// @details utilise du raycasting pour détecter les collisions
    bool collidesWith(const sf::FloatRect& rectangle) override;

    void onCollision(Entity* entity) override;
    
    bool update(float dt) override;
    
    /// @brief ~Laser est le destructeur par default de Laser
    ~Laser() = default;
};
