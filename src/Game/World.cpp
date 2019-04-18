//
// Created by petersenyszyn on 4/7/19.
//

#include "../../include/Game/World.hpp"

namespace Shock
{
namespace Game
{
    World::World( Core::ContextBuffer* context ) :
    _context( context )
    {

    }

    void World::handleEvent( Input::InputManager& inputManager )
    {
        _instanceManager.handleEvent( inputManager ) ;
    }

    void World::update( sf::Time dt )
    {
        _instanceManager.update( dt ) ;
    }

    void World::render( sf::RenderTarget& target, sf::RenderStates states )
    {
        _instanceManager.render( target, states ) ;
    }
}}