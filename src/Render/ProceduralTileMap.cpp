//
// Created by petersenyszyn on 4/30/19.
//

#include "../../include/Render/ProceduralTileMap.hpp"

#include <iostream>
#include <random>

namespace Shock::Render
{
    ProceduralTileMap::ProceduralTileMap( Game::Player* playerContext ) :
    _playerContext( playerContext ),
    _tileSize( 0, 0 ),
    _chunkSize( 0, 0 ),
    _renderingNewChunk( false )
    {
    }

    void ProceduralTileMap::handleEvent( Shock::Input::InputManager& inputManager )
    {
    }

    void ProceduralTileMap::update( sf::Time dt )
    {
    }

    void ProceduralTileMap::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {
        states.texture = &_tileset ;

        for ( const auto& iter : _renderedChunks )
            target.draw( iter->vertices, states ) ;
    }

    void ProceduralTileMap::init( const std::string& tilesheetPath, sf::Vector2u tileSize,
                                  sf::Vector2u chunkSize )
    {
        if ( !_tileset.loadFromFile( tilesheetPath ) )
        {
            std::cout << "Error loading tilesheet for ProceduralTileMap!" << std::endl ;

            return ;
        }

        _tileSize      = tileSize ;
        _chunkSize     = chunkSize ; //x = # of tiles across width, y = # of tiles across height

        generateInitialMap() ;
    }

    void ProceduralTileMap::generateInitialMap()
    {
        //Generate initial chunks in a rectangular grid around the player
        /*
         * x x x
         * x p x
         * x x x
         *
         * where x = chunk, p = player (still want to gen chunk on player obviously)
        */

        auto chunkSizePx = sf::Vector2f( _chunkSize.x * _tileSize.x, _chunkSize.y * _tileSize.y ) ;
        auto playerPos = _playerContext->getWorldCoords() ;

        //We want to find the top left coord of rectangle
        auto rectTopLeftCoord = sf::Vector2f( playerPos.x - 1.5f * chunkSizePx.x,
                                              playerPos.y - 1.5f * chunkSizePx.y ) ;
        auto origTopLeft = rectTopLeftCoord ;

        for ( int i = 0 ; i < 3 ; i++ )
        {
            for ( int j = 0 ; j < 3 ; j++ )
            {
                generateChunk( rectTopLeftCoord ) ;

                rectTopLeftCoord.x += chunkSizePx.x ;
            }

            rectTopLeftCoord.y += chunkSizePx.y ;
            rectTopLeftCoord.x  = origTopLeft.x ;
        }
    }

    void ProceduralTileMap::generateChunk( sf::Vector2f topLeftWorldCoord )
    {
        std::cout << "Generating chunk: " << topLeftWorldCoord.x << ", " << topLeftWorldCoord.y << std::endl ;

        auto chunk = std::make_shared<Chunk>( _chunkSize ) ;

        //FIXME: add proper noise algorithm

        std::random_device rd ;
        std::mt19937 e2( rd() ) ;
        std::uniform_real_distribution<> dist( 1, 7 ) ;

        for ( int i = 0 ; i < _chunkSize.x ; i++ )
        {
            for ( int j = 0 ; j < _chunkSize.y ; j++ )
            {
                int tileNumber = dist( e2 ) ;

                //Find uv coordinate
                int tu = tileNumber % ( _tileset.getSize().x / _tileSize.x ) ;
                int tv = tileNumber / ( _tileset.getSize().x / _tileSize.x ) ;

                sf::Vertex* quad = &chunk->vertices[( i + j * _chunkSize.x ) * 4] ;

                int tx = _tileSize.x ;
                int ty = _tileSize.y ;

                quad[0].position = sf::Vector2f(   topLeftWorldCoord.x + ( i * tx ), topLeftWorldCoord.y + ( j * ty ) ) ;
                quad[1].position = sf::Vector2f(   quad[0].position.x + tx, quad[0].position.y ) ;
                quad[2].position = sf::Vector2f(   quad[1].position.x, quad[1].position.y + ty ) ;
                quad[3].position = sf::Vector2f(   quad[0].position.x, quad[2].position.y ) ;

                //Define 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(   tu       * _tileSize.x,   tv       * _tileSize.y ) ;
                quad[1].texCoords = sf::Vector2f( ( tu + 1 ) * _tileSize.x,   tv       * _tileSize.y ) ;
                quad[2].texCoords = sf::Vector2f( ( tu + 1 ) * _tileSize.x, ( tv + 1 ) * _tileSize.y ) ;
                quad[3].texCoords = sf::Vector2f(   tu       * _tileSize.x, ( tv + 1 ) * _tileSize.y ) ;

                //Create tile abstraction
                Tile tile( tileNumber, sf::FloatRect( quad[0].position.x,  quad[0].position.y,
                                                      quad[1].position.x - quad[0].position.x,
                                                      quad[2].position.y - quad[0].position.y ) ) ;

                chunk->tiles.push_back( tile ) ;
            }
        }

        _chunks.push_back( chunk ) ;
        _renderedChunks.push_back( chunk ) ;
    }

    ProceduralTileMap::Chunk::Chunk( sf::Vector2u size ) :
    tiles(),
    vertices()
    {
        vertices.setPrimitiveType( sf::Quads ) ;
        vertices.resize( size.x * size.y * 4 ) ;
    }
}