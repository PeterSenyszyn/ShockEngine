//
// Created by petersenyszyn on 4/18/19.
//

#ifndef SHOCKENGINE_COLLISIONCOMPONENT_HPP
#define SHOCKENGINE_COLLISIONCOMPONENT_HPP

#include "Component.hpp"

namespace Shock::Game
{
    class CollisionComponent : public Component
    {
    public:
        CollisionComponent( std::string name ) ;
        ~CollisionComponent() override = default ;

        void handleEvent( Input::InputManager& inputManager ) override ;
        void update( sf::Time dt ) override ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) const override ;
    } ;
}

#endif //SHOCKENGINE_COLLISIONCOMPONENT_HPP