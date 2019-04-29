//
// Created by petersenyszyn on 4/7/19.
//

#include "../../include/Game/Instance.hpp"

namespace Shock::Game
{
    Instance::Instance( Player* playerContext ) :
    _delete( false ),
    _camera( sf::FloatRect( playerContext->getWorldCoords() , { 1920 / 2.f, 1080 / 2.f } ), playerContext ),
    _playerContext( playerContext ),
    _tilemap( nullptr )
    {
    }

    void Instance::handleEvent( Input::InputManager& inputManager )
    {
        if ( _tilemap )
            _tilemap->handleEvent( inputManager ) ;

        for ( const auto& iter : _entities )
            iter->handleEvent( inputManager ) ;
    }

    void Instance::update( sf::Time dt )
    {
        _camera.update( dt ) ;

        if ( _tilemap )
            _tilemap->update( dt ) ;

        for ( const auto& iter : _entities )
            iter->update( dt ) ;
    }

    void Instance::render( sf::RenderTarget& target, sf::RenderStates states )
    {
        _camera.render( target ) ;

        if ( _tilemap )
            _tilemap->render( target, states ) ;

        for ( const auto& iter : _entities )
            iter->render( target, states ) ;
    }

    void Instance::addTilemap( const std::string& mapPath )
    {
        _tilemap = std::make_unique<Render::TileMap>() ;
        _tilemap->load( mapPath ) ;

        _camera.setMapSize( _tilemap->getTileMapSize() ) ;

        _playerContext->defineCollisionBounds( _tilemap->getCollisionPoints() ) ;
    }

    const void Instance::markForDeletion( bool value )
    { _delete = value ; }
    const bool Instance::needsDelete() const
    { return _delete ; }
}