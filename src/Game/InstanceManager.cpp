//
// Created by petersenyszyn on 4/7/19.
//

#include "../../include/Game/InstanceManager.hpp"

namespace Shock
{
namespace Game
{
    void InstanceManager::handleEvent( Input::InputManager& inputManager )
    {
        for ( const auto& iter : _instances )
            iter->handleEvent( inputManager ) ;
    }

    void InstanceManager::update( sf::Time dt )
    {
        for ( auto iter = _instances.begin() ; iter != _instances.end() ; iter++ )
        {
            cleanInstances( iter ) ;

            (*iter)->update( dt ) ;
        }
    }

    void InstanceManager::render( sf::RenderTarget& target, sf::RenderStates states )
    {
        for ( const auto& iter : _instances )
            iter->render( target, states ) ;
    }

    void InstanceManager::addInstance( Instance::Ptr instance )
    {
        _instances.push_back( std::move( instance ) ) ;
    }

    void InstanceManager::cleanInstances( std::vector<Instance::Ptr>::iterator iter )
    {
        if ( (*iter)->needsDelete() )
            _instances.erase( iter ) ;
    }
}}