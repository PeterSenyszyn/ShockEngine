//
// Created by petersenyszyn on 4/12/19.
//

#include "../../../include/Game/Components/MovementComponent.hpp"

namespace Shock::Game
{
    MovementComponent::MovementComponent( sf::Vector2f speedVector, sf::Transformable* objectToMove ) :
    Component( "Movement Component" ),
    _speedVector( speedVector ),
    _velocityVector( sf::Vector2f() ),
    _objectToMove( objectToMove ),
    _upKey(), _leftKey(), _downKey(), _rightKey()
    {
        //Set a default set of hot keys
        setHotKeys( KAI::WHOLD, KAI::AHOLD, KAI::SHOLD, KAI::DHOLD ) ;
    }

    void MovementComponent::handleEvent( Input::InputManager& inputManager )
    {
        //Lambdas to shorten ifs
        auto active     = [&]( auto& key ) { return inputManager.keyActive( key ) ; } ;
        auto activeDiag = [&]( auto& tuple )
        {
            return active( std::get<0>( tuple ) ) && active( std::get<1>( tuple ) ) ;
        } ;

        if ( active( _upKey ) )
            _velocityVector = sf::Vector2f( 0.f, _speedVector.y ) ;

        else if ( active( _leftKey ) )
            _velocityVector = sf::Vector2f( -_speedVector.x, 0.f ) ;

        else if ( active( _downKey ) )
            _velocityVector = sf::Vector2f( 0.f, -_speedVector.y ) ;

        else if ( active( _rightKey ) )
            _velocityVector = sf::Vector2f( _speedVector.x, 0.f ) ;

        else if ( activeDiag( _upLeftDiagKey ) )
            _velocityVector = sf::Vector2f( -_speedVector.x, _speedVector.y ) ;

        else if ( activeDiag( _downLeftDiagKey ) )
            _velocityVector = sf::Vector2f( -_speedVector.x, -_speedVector.y ) ;

        else if ( activeDiag( _downRightDiagKey ) )
            _velocityVector = sf::Vector2f( _speedVector.x, -_speedVector.y ) ;

        else if ( activeDiag( _upRightDiagKey ) )
            _velocityVector = sf::Vector2f( _speedVector.x, _speedVector.y ) ;
    }

    void MovementComponent::update( sf::Time dt )
    {
        _objectToMove->move( _velocityVector * dt.asSeconds() ) ;
    }

    void MovementComponent::setHotKeys( KAI upKey, KAI leftKey, KAI downKey, KAI rightKey )
    {
        _upKey    = upKey ;
        _leftKey  = leftKey ;
        _downKey  = downKey ;
        _rightKey = rightKey ;

        _upLeftDiagKey      = std::make_tuple( _upKey, _leftKey ) ;
        _downLeftDiagKey    = std::make_tuple( _downKey, _leftKey ) ;
        _downRightDiagKey   = std::make_tuple( _downKey, _rightKey ) ;
        _upRightDiagKey     = std::make_tuple( _upKey, _rightKey ) ;
    }
}