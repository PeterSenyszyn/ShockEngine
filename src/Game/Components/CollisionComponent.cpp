//
// Created by petersenyszyn on 4/18/19.
//

#include "../../../include/Game/Components/CollisionComponent.hpp"

namespace Shock::Game
{
    CollisionComponent::CollisionComponent( std::string name ) : Component( name )
    {

    }

    void CollisionComponent::handleEvent( Input::InputManager& inputManager )
    {
        Component::handleEvent( inputManager );
    }

    void CollisionComponent::update( sf::Time dt )
    {
        Component::update( dt );
    }

    void CollisionComponent::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {
        Component::render( target, states );
    }
}