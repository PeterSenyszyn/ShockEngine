//
// Created by petersenyszyn on 4/12/19.
//

#include "../../../include/Game/Components/MovementComponent.hpp"

namespace Shock
{
namespace Game
{
    MovementComponent::MovementComponent( sf::Vector2f speedVector ) :
    Component( "Movement Component" ),
    _speedVector( speedVector )
    {

    }

    void MovementComponent::handleEvent( Input::InputManager& inputManager )
    {

    }

    void MovementComponent::update( sf::Time dt )
    {

    }
}}