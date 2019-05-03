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
    _tileMap( nullptr ),
    _proceduralTileMap( nullptr )
    {
    }

    void Instance::handleEvent( Input::InputManager& inputManager )
    {
        if ( _tileMap )
            _tileMap->handleEvent( inputManager ) ;

        if ( _proceduralTileMap )
            _proceduralTileMap->handleEvent( inputManager ) ;

        for ( const auto& iter : _entities )
            iter->handleEvent( inputManager ) ;
    }

    void Instance::update( sf::Time dt )
    {
        _camera.update( dt ) ;

        if ( _tileMap )
            _tileMap->update( dt ) ;

        if ( _proceduralTileMap )
            _proceduralTileMap->update( dt ) ;

        for ( const auto& iter : _entities )
            iter->update( dt ) ;
    }

    void Instance::render( sf::RenderTarget& target, sf::RenderStates states )
    {
        _camera.render( target ) ;

        if ( _tileMap )
            _tileMap->render( target, states ) ;

        if ( _proceduralTileMap )
            _proceduralTileMap->render( target, states ) ;

        for ( const auto& iter : _entities )
            iter->render( target, states ) ;
    }

    void Instance::addTileMap( const std::string& mapPath )
    {
        _tileMap = std::make_unique<Render::TileMap>() ;
        _tileMap->load( mapPath ) ;

        _camera.setMapSize( _tileMap->getTileMapSize() ) ;

        _playerContext->defineCollisionBounds( _tileMap->getCollisionPoints() ) ;
    }

    void Instance::addProceduralTileMap( const std::string& tilesetPath, sf::Vector2u tileSize,
                                         sf::Vector2u chunkSize  )
    {
        _proceduralTileMap = std::make_unique<Render::ProceduralTileMap>( _playerContext ) ;
        _proceduralTileMap->init( tilesetPath, tileSize, chunkSize ) ;

        _playerContext->defineCollisionBounds( _proceduralTileMap->getCollisionPoints() ) ;
    }

    const void Instance::markForDeletion( bool value )
    { _delete = value ; }
    const bool Instance::needsDelete() const
    { return _delete ; }
}