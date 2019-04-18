//
// Created by petersenyszyn on 4/7/19.
//

#include "../../include/Game/Instance.hpp"

namespace Shock::Game
{
    Instance::Instance() :
    _delete( false ),
    _tilemap( nullptr )
    {
    }

    void Instance::handleEvent( Input::InputManager& inputManager )
    {
        for ( const auto& iter : _entities )
            iter->handleEvent( inputManager ) ;

        if ( _tilemap )
            _tilemap->handleEvent( inputManager ) ;
    }

    void Instance::update( sf::Time dt )
    {
        for ( const auto& iter : _entities )
            iter->update( dt ) ;

        if ( _tilemap )
            _tilemap->update( dt ) ;
    }

    void Instance::render( sf::RenderTarget& target, sf::RenderStates states )
    {
        for ( const auto& iter : _entities )
            iter->render( target, states ) ;

        if ( _tilemap )
            _tilemap->render( target, states ) ;
    }

    void Instance::addTilemap( const std::string& mapPath )
    {
        _tilemap = std::make_unique<Render::TileMap>() ;
        _tilemap->load( mapPath ) ;
    }

    const void Instance::markForDeletion( bool value )
    { _delete = value ; }
    const bool Instance::needsDelete() const
    { return _delete ; }
}