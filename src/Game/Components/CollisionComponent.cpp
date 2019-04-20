//
// Created by petersenyszyn on 4/18/19.
//

#include "../../../include/Game/Components/CollisionComponent.hpp"

namespace Shock::Game
{
    CollisionComponent::CollisionComponent( Entity* parentEntity, MovementComponent* movementComponent,
                                            sf::FloatRect* entityBounds ) :
    Component( "Collision Component", parentEntity ),
    _movementComponent( movementComponent ),
    _entityBounds( entityBounds ),
    _potentialMapCollisions()
    {

    }

    void CollisionComponent::update( sf::Time dt )
    {
        Component::update( dt ) ;

        _movementComponent->setColliding( false ) ;

        //Instead of just checking if entity's bounds hits potential collision points,
        //we want to predict if on next tick a collision will occur to stop before the objects collide
        sf::Vector2f vel  = _movementComponent->getVelocityVector() ;
        sf::Vector2f offsettedPos( _entityBounds->left + ( vel.x * dt.asSeconds() ),
                                   _entityBounds->top  + ( vel.y * dt.asSeconds() ) ) ;

        sf::FloatRect nextTickBounds = sf::FloatRect( offsettedPos, sf::Vector2f( _entityBounds->width, _entityBounds->height ) ) ;

        for ( const auto& potentialCollision : *_potentialMapCollisions )
        {
            if ( nextTickBounds.intersects( potentialCollision ) )
                _movementComponent->setColliding( true ) ;
        }
    }

    void CollisionComponent::setPotentialCollisions( std::vector<sf::FloatRect>* potentialCollisions )
    { _potentialMapCollisions = potentialCollisions ; }
}