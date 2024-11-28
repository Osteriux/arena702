/// @file projectile.h
/// @brief Déclaration de la classe Projectile pour la gestion des projectiles dans le jeu.
/// 
/// La classe Projectile hérite de la classe Attack et représente une attaque qui se déplace
/// en ligne droite. Elle gère les propriétés spécifiques aux projectiles telles que la direction,
/// la vitesse, la durée de vie, et le nombre de cibles que le projectile peut traverser.
/// Elle fournit également des méthodes pour gérer les collisions avec les entités et mettre à jour
/// l'état du projectile en fonction du temps écoulé.

#pragma once
#include "attack.h"
#include "../../entitys/entity.h"

/// @brief représente une attaque qui se déplace en ligne droite. <br/>
/// La classe Projectile hérite de la classe Attack et représente une attaque qui se déplace
/// en ligne droite. Elle gère les propriétés spécifiques aux projectiles telles que la direction,
/// la vitesse, la durée de vie, et le nombre de cibles que le projectile peut traverser.
/// Elle fournit également des méthodes pour gérer les collisions avec les entités et mettre à jour
/// l'état du projectile en fonction du temps écoulé.
class Projectile : public Attack {
    private:
        /// @brief direction du projectile
        sf::Vector2f direction;

        /// @brief nombre de cible que le projectile peut traverser 
        int pierce;
    public:
        /// @brief Constructeur de Projectile
        /// @param owner entité qui a lancé le projectile
        /// @param damage dégâts causés par le projectile
        /// @param speed vitesse de déplacement du projectile
        /// @param duration durée de vie du projectile
        /// @param pierce nombre de cible que le projectile peut traverser
        /// @param color couleur du projectile
        Projectile(Entity* owner, float damage, float speed, float duration, int pierce, sf::Color color);

        /// @brief appelé lorsqu'un projectile entre en collision avec une entité
        /// @param entity entité avec laquelle le projectile est entré en collision
        void onCollision(Entity* entity) override;

        /// @brief met à jour le projectile en fonction du temps écoulé
        /// @param dt delta time
        /// @return si le projectile est toujours en vie
        bool update(float dt) override;

        /// @brief ~Projectile est le destructeur par default de Projectile
        ~Projectile() = default;
};