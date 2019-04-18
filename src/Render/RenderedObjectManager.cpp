//
// Created by Peter Senyszyn on 7/24/18.
//

#include "../../include/Render/RenderedObjectManager.hpp"

namespace Shock
{
namespace Render
{
    void RenderedObjectManager::addRenderedObject( const std::string& id,
                                                   std::unique_ptr<RenderedObject> object )
    {
        //Insert and check success
        auto inserted = _objects.insert( std::make_pair( id, std::move( object ) ) ) ;

        assert( inserted.second ) ;
    }

    RenderedObject& RenderedObjectManager::getRenderedObject( const std::string& id )
    {
        auto found = _objects.find( id ) ;

        assert( found != _objects.end() ) ;

        return *found->second ;
    }

    const RenderedObject& RenderedObjectManager::getRenderedObject( const std::string& id ) const
    {
        auto found = _objects.find( id ) ;

        assert( found != _objects.end() ) ;

        return *found->second ;
    }

    void RenderedObjectManager::handleEvent( Shock::Input::InputManager& inputManager )
    {
        for ( const auto& iter : _objects )
        {
            iter.second->handleEvent( inputManager ) ;
        }
    }

    void RenderedObjectManager::update( sf::Time dt )
    {
        for ( const auto& iter : _objects )
        {
            if ( iter.second->isEnabled() )
            {
                iter.second->update( dt ) ;
            }
        }
    }

    void RenderedObjectManager::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {
        for ( const auto& iter : _objects )
        {
            if ( iter.second->isEnabled() )
                target.draw( *iter.second ) ;
        }
    }

    unsigned long RenderedObjectManager::getNumRenderedObjects() const
    { return _objects.size() ; }
}}