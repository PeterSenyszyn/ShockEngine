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
    }

    void Player::handleEvent( Input::InputManager& inputManager )
    {
        Entity::handleEvent( inputManager ) ;

        using namespace Shock::Input ;
        if ( inputManager.keyActive( KAI::WHOLD ) )
        {

        }

        else if ( inputManager.keyActive( KAI::AHOLD ) )
        {

        }

        else if ( inputManager.keyActive( KAI::SHOLD ) )
        {

        }

        else if ( inputManager.keyActive( KAI::DHOLD ) )
        {

        }
    }

    void Player::update( sf::Time dt )
    {
        Entity::update( dt ) ;
    }

    void Player::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {
        Entity::render( target, states ) ;
    }
}}