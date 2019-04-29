//
// Created by petersenyszyn on 4/12/19.
//

#ifndef SHOCKENGINE_PLAYER_HPP
#define SHOCKENGINE_PLAYER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Entity.hpp"
#include "Components/MovementComponent.hpp"

namespace Shock::Game
{
    class Player : public Entity
    {
    public:
        Player( sf::Texture* texture, sf::RenderTarget* targetContext ) ;

        ~Player() override = default ;

        void handleEvent( Input::InputManager& inputManager ) override ;
        void update( sf::Time dt ) override ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) const override ;

        void defineCollisionBounds( std::vector<sf::FloatRect>& collisionPoints ) ;

        void setCoords() override ;

    private:
        void attachComponents() ;

    //Consts
    private:
        const float _playerSpeedPX = 100.f ; //in pixels

    private:
        sf::Texture* _texture ;
        sf::Sprite _sprite ;

        std::vector<sf::FloatRect> _potentialCollisionPoints ;
    } ;
}

#endif //SHOCKENGINE_PLAYER_HPP