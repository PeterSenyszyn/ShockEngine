//
// Created by petersenyszyn on 4/21/19.
//

#ifndef SHOCKENGINE_CAMERA_HPP
#define SHOCKENGINE_CAMERA_HPP

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Entity.hpp"
#include "../Game/Components/MovementComponent.hpp"

namespace Shock::Game
{
    class Camera
    {
    public:
        Camera( sf::FloatRect viewRect, Entity* entityToFollow ) ;

        void update( sf::Time dt ) ;
        void render( sf::RenderTarget& target ) ;

        const void setMapSize( sf::Vector2u mapSize ) ;

    private:
        std::shared_ptr<MovementComponent> retrieveMovementComponent( std::shared_ptr<Component> component ) ;

    private:
        sf::View _view ;
        sf::Vector2f _cameraVector ;

        sf::Vector2u _mapSize ;
        bool _mapSizeSet ;

        Entity* _followedEntity ;
        std::shared_ptr<MovementComponent> _mc ;

        sf::Vector2f _topLeftCoord, _bottomRightCoord ;
        sf::Vector2f _defaultCameraPos ;
    } ;
}

#endif //SHOCKENGINE_CAMERA_HPP