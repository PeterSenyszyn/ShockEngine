//
// Created by petersenyszyn on 4/12/19.
//

#ifndef SHOCKENGINE_PLAYER_HPP
#define SHOCKENGINE_PLAYER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Entity.hpp"
#include "Components/MovementComponent.hpp"

namespace Shock
{
namespace Game
{
    class Player : public Entity
    {
    public:
        Player( sf::Texture* texture ) ;

        ~Player() override = default ;

        void handleEvent( Input::InputManager& inputManager ) override ;
        void update( sf::Time dt ) override ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) const override ;

        void defineCollisionBounds( std::vector<sf::FloatRect>& collisionPoints ) ;

    private:
        void attachComponents() ;

    //Consts
    private:
        const float _playerSpeedPX = 100.f ; //in pixels

    private:
        sf::Texture* _texture ;
        sf::Sprite _sprite ;

        //Since sprite getGlobalBounds returns a copy instead of a reference, we have to cache
        //_sprite's bounds to pass to the collision component
        sf::FloatRect _spriteBounds ;

        std::vector<sf::FloatRect> _potentialCollisionPoints ;
    } ;
}}

#endif //SHOCKENGINE_PLAYER_HPP