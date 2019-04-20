//
// Created by petersenyszyn on 4/12/19.
//

#include "../../../include/Game/Components/MovementComponent.hpp"

#include <iostream>

namespace Shock::Game
{
    MovementComponent::MovementComponent( Entity* parentEntity, sf::Vector2f speedVector, sf::Transformable* objectToMove ) :
    Component( "Movement Component", parentEntity ),
    _speedVector( speedVector ),
    _velocityVector( sf::Vector2f() ),
    _colliding( false ),
    _objectToMove( objectToMove ),
    _upKey(), _leftKey(), _downKey(), _rightKey()
    {
        //Set a default set of hot keys
        setHotKeys( KAI::WHOLD, KAI::AHOLD, KAI::SHOLD, KAI::DHOLD ) ;
    }

    void MovementComponent::handleEvent( Input::InputManager& inputManager )
    {
        _velocityVector = sf::Vector2f( 0.f, 0.f ) ;

        //Lambdas to shorten ifs
        auto active = [&]( auto& key ) { return inputManager.keyActive( key ) ; } ;

        if ( active( _upKey ) )
            _velocityVector += sf::Vector2f( 0.f, -_speedVector.y ) ;

        if ( active( _leftKey ) )
            _velocityVector += sf::Vector2f( -_speedVector.x, 0.f ) ;

        if ( active( _downKey ) )
            _velocityVector += sf::Vector2f( 0.f, _speedVector.y ) ;

        if ( active( _rightKey ) )
            _velocityVector += sf::Vector2f( _speedVector.x, 0.f ) ;
    }

    void MovementComponent::update( sf::Time dt )
    {
        if ( !_colliding )
            _objectToMove->move( _velocityVector * dt.asSeconds() ) ;
    }

    void MovementComponent::setHotKeys( KAI upKey, KAI leftKey, KAI downKey, KAI rightKey )
    {
        _upKey    = upKey ;
        _leftKey  = leftKey ;
        _downKey  = downKey ;
        _rightKey = rightKey ;
    }

    const void MovementComponent::setVelocityVector( sf::Vector2f velocity )
    { _velocityVector = velocity ; }
    const sf::Vector2f& MovementComponent::getVelocityVector()
    { return _velocityVector ; }

    const void MovementComponent::setColliding( bool colliding )
    { _colliding = colliding ; }
    const bool MovementComponent::isColliding() const
    { return _colliding ; }
}