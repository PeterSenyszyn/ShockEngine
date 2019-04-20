//
// Created by petersenyszyn on 4/18/19.
//

#ifndef SHOCKENGINE_COLLISIONCOMPONENT_HPP
#define SHOCKENGINE_COLLISIONCOMPONENT_HPP

#include "Component.hpp"
#include "MovementComponent.hpp"

namespace Shock::Game
{
    class CollisionComponent : public Component
    {
    public:
        CollisionComponent( Entity* parentEntity, MovementComponent* movementComponent,
                            sf::FloatRect* entityBounds ) ;
        ~CollisionComponent() override = default ;

        void update( sf::Time dt ) override ;

        void setPotentialCollisions( std::vector<sf::FloatRect>* potentialCollisions ) ;

    private:
        MovementComponent* _movementComponent ; //We need this to control entity's movement

        sf::FloatRect* _entityBounds ; //Dynamic, so we keep a pointer

        std::vector<sf::FloatRect>* _potentialMapCollisions ;
    } ;
}

#endif //SHOCKENGINE_COLLISIONCOMPONENT_HPP