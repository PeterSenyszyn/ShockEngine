//
// Created by petersenyszyn on 4/7/19.
//

#include "../../include/Game/Instance.hpp"

namespace Shock
{
namespace Game
{
    Instance::Instance() :
    _delete( false )
    {

    }

    void Instance::handleEvent( Input::InputManager& inputManager )
    {
        for ( const auto& iter : _entities )
            iter->handleEvent( inputManager ) ;
    }

    void Instance::update( sf::Time dt )
    {
        for ( const auto& iter : _entities )
            iter->update( dt ) ;
    }

    void Instance::render( sf::RenderTarget& target, sf::RenderStates states )
    {
        for ( const auto& iter : _entities )
            iter->render( target, states ) ;
    }

    const void Instance::markForDeletion( bool value )
    { _delete = value ; }
    const bool Instance::needsDelete() const
    { return _delete ; }
}}