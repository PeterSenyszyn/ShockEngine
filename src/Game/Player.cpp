//
// Created by petersenyszyn on 4/12/19.
//

#include <iostream>

#include "../../include/Game/Player.hpp"

namespace Shock
{
namespace Game
{
    Player::Player( sf::Texture* texture ) :
    _texture( texture )
    {
        if ( _texture != nullptr )
            _sprite.setTexture( *_texture ) ;

        else
        {
            std::cout << "Warning: Player object created with nullptr texture!" << std::endl ;
        }

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

    void Player::attachComponents()
    {
        auto movement = std::make_unique<MovementComponent>( sf::Vector2f( _playerSpeedPX, _playerSpeedPX ), &_sprite ) ;
        movement->setHotKeys( KAI::WHOLD, KAI::AHOLD, KAI::SHOLD, KAI::DHOLD ) ; //Redundant, but keep here as reminder

        addComponent( std::move( movement ) ) ;
    }
}}