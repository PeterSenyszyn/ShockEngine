//
// Created by petersenyszyn on 4/21/19.
//

#include "../../include/Game/Camera.hpp"

#include <iostream>

namespace Shock::Game
{
    Camera::Camera( sf::FloatRect viewRect, Shock::Game::Entity* entityToFollow ) :
    _view( viewRect ),
    _cameraVector( 0, 0 ),
    _mapSize( 0, 0 ),
    _mapSizeSet( false ),
    _followedEntity( entityToFollow ),
    _topLeftCoord( 0.f, 0.f ), _bottomRightCoord( 0.f, 0.f ),
    _defaultCameraPos( 0.f, 0.f )
    {
        _mc = retrieveMovementComponent( _followedEntity->getComponent( "Movement Component" ) ) ;

        if ( _mc )
            _cameraVector = _mc->getVelocityVector() ;

        else
            std::cout << "Error retrieving movement component from followedEntity" << std::endl ;
    }

    //FIXME
    //When the entity has fast movement speeds, it can cause the camera to get slightly offset
    void Camera::update( sf::Time dt )
    {
        if ( !_mapSizeSet )
            return ;

        _cameraVector = _mc->getVelocityVector() ;

        if ( _topLeftCoord.x <= 0.f )
        {
            _topLeftCoord.x = 0.f ;

            if ( _cameraVector.x < 0.f )
                _cameraVector.x = 0.f ;

            else if ( _cameraVector.x > 0.f )
            {
                if ( _followedEntity->getCenterCoords().x <= _view.getSize().x / 2.f )
                    _cameraVector.x = 0.f ;
            }
        }

        else if ( _bottomRightCoord.x >= _mapSize.x )
        {
            _bottomRightCoord.x = _mapSize.x ;

            if ( _cameraVector.x > 0.f )
                _cameraVector.x = 0.f ;

            else if ( _cameraVector.x < 0.f )
            {
                if ( _followedEntity->getCenterCoords().x + ( _view.getSize().x / 2.f ) >= _mapSize.x )
                    _cameraVector.x = 0.f ;
            }
        }

        if ( _topLeftCoord.y <= 0.f )
        {
            _topLeftCoord.y = 0.f ;

            if ( _cameraVector.y < 0.f )
                _cameraVector.y = 0.f ;

            else if ( _cameraVector.y > 0.f )
            {
                if ( _followedEntity->getCenterCoords().y - ( _view.getSize().y / 2.f ) <= 0.f )
                    _cameraVector.y = 0.f ;
            }
        }

        else if ( _bottomRightCoord.y >= _mapSize.y )
        {
            _bottomRightCoord.y = _mapSize.y ;

            if ( _cameraVector.y > 0.f )
                _cameraVector.y = 0.f ;

            else if ( _cameraVector.y < 0.f )
            {
                if ( _followedEntity->getCenterCoords().y + ( _view.getSize().y / 2.f ) >= _mapSize.y )
                    _cameraVector.y = 0.f ;
            }
        }

        _view.move( _cameraVector * dt.asSeconds() ) ;
    }

    void Camera::render( sf::RenderTarget& target )
    {
        static int runCount = 1 ;
        if ( runCount == 1 )
        {
            _defaultCameraPos = _followedEntity->getWorldCoords() ;
            _view.setCenter( _followedEntity->getWorldCoords() ) ;
            runCount++ ;
        }

        target.setView( _view ) ;

        _topLeftCoord = target.mapPixelToCoords( sf::Vector2i( 0, 0 ), _view ) ;
        _bottomRightCoord = target.mapPixelToCoords( sf::Vector2i( 1920, 1080 ), _view ) ; //FIXME: add global resolution constants
    }

    const void Camera::setMapSize( sf::Vector2u mapSize )
    {
        _mapSize = mapSize ;
        _mapSizeSet = true ;
    }

    std::shared_ptr<MovementComponent> Camera::retrieveMovementComponent( std::shared_ptr<Component> component )
    {
        if ( !component )
        {
            std::cout << "Error: Camera's followedEntity does not have an attached movement component!" << std::endl;

            return nullptr ;
        }

        auto mc = std::dynamic_pointer_cast<MovementComponent>( component ) ;

        if ( !mc )
        {
            std::cout << "Error: could not cast Camera's followedEntity's movement component!" << std::endl ;

            return nullptr ;
        }

        return mc ;
    }
}