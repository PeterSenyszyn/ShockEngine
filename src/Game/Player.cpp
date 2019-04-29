//
// Created by petersenyszyn on 4/12/19.
//

#include <iostream>

#include "../../include/Game/Player.hpp"
#include "../../include/Game/Components/CollisionComponent.hpp"

namespace Shock::Game
{
    Player::Player( sf::Texture* texture, sf::RenderTarget* targetContext ) :
    Entity( targetContext ),
    _texture( texture )
    {
        if ( _texture != nullptr )
            _sprite.setTexture( *_texture ) ;

        else
        {
            std::cout << "Warning: Player object created with nullptr texture!" << std::endl ;
        }

        _sprite.setPosition( 1000, 850 ) ;

        attachComponents() ;
    }

    void Player::handleEvent( Input::InputManager& inputManager )
    {
        Entity::handleEvent( inputManager ) ;
    }

    void Player::update( sf::Time dt )
    {
        Entity::update( dt ) ;
    }

    void Player::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {
        Entity::render( target, states ) ;

        target.draw( _sprite, states ) ;
    }

    void Player::defineCollisionBounds( std::vector<sf::FloatRect>& collisionPoints )
    {
        _potentialCollisionPoints = collisionPoints ;
    }

    void Player::attachComponents()
    {
        auto movement = std::make_shared<MovementComponent>( this, sf::Vector2f( _playerSpeedPX, _playerSpeedPX ), &_sprite ) ;
        movement->setHotKeys( KAI::WHOLD, KAI::AHOLD, KAI::SHOLD, KAI::DHOLD ) ; //Redundant, but keep here as reminder

        auto collision = std::make_shared<CollisionComponent>( this, movement.get(), &_bounds ) ;
        collision->setPotentialCollisions( &_potentialCollisionPoints ) ;

        addComponent( movement ) ;
        addComponent( collision ) ;
    }

    void Player::setCoords()
    {
        _worldCoords  = _sprite.getPosition() ;
        _bounds       = _sprite.getGlobalBounds() ;
    }
}