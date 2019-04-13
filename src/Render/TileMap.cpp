//
// Created by petersenyszyn on 4/6/19.
//

#include "../../include/Render/TileMap.hpp"
#include "../../include/Utilities/StringUtils.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

/* The format for a .stm file is as follows:
 * Line 1 (path to tileset)
 * Line 2 (tile size width)
 * Line 3 (tile size height)
 * Line 4 (tilemap width in terms of #tiles)
 * Line 5 (tilemap height in terms of #tiles)
 * Line 6 (begin tilemap data delimited by commas)
 */

//Example below:
/* assets/blah.png
 * 32
 * 16
 * 8
 * 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
 * 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
 * 1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
 * 0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
 * 0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
 * 0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
 * 2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
 * 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1
 */

namespace Shock
{
namespace Render
{
    TileMap::TileMap() :
    _tilesetPath( "" ),
    _tileSize(    { 0, 0 } ),
    _tilemapSize( { 0, 0 } )
    {
    }

    bool TileMap::load( const std::string& tilemapPath )
    {
        //Make sure path has .stm as file extension
        if ( !StringUtils::hasEnding( tilemapPath, ".stm" ) )
        {
            std::cout << "Unable to load tilemap path: " << tilemapPath << ", wrong file extension!" << std::endl ;

            return false;
        }

        std::ifstream file( tilemapPath ) ;

        //Ensure file upholds .stm file standards
        if ( !analyzeFile( file ) )
        {
            std::cout << "Unable to pass .stm file standards on: " << tilemapPath << std::endl ;

            return false ;
        }

        //After analyzeFile, we start on line # PRE_TILEMAP_DEF_LINE_COUNT + 1
        //Now we want to get tile data (delimited by commas)

        std::string lineBuffer ;

        unsigned int lineIter = 0 ;
        while ( std::getline( file, lineBuffer, ',' ) )
        {
            std::istringstream iss( lineBuffer ) ;

            for ( unsigned int i = 0 ; i < _tilemapSize.x ; i++ )
            {
                iss >> _tileData( i, lineIter ) ;
            }

            lineIter++ ;
        }

        return true ;
    }

    void TileMap::handleEvent( Input::InputManager& inputManager )
    {
    }

    void TileMap::update( sf::Time dt )
    {
    }

    void TileMap::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {
        states.texture = &_tileset ;

        target.draw( _vertices, states ) ;
    }

    //Verify file structure and correct number of lines, as well as set member data
    bool TileMap::analyzeFile( std::ifstream& file )
    {
        auto lineCount = std::count( std::istreambuf_iterator<char>( file ),
                                     std::istreambuf_iterator<char>(), '\n' ) ;

        if ( lineCount > PRE_TILEMAP_DEF_LINE_COUNT )
        {
            int currentLine = 1 ;
            std::string lineBuffer[PRE_TILEMAP_DEF_LINE_COUNT] ;

            while ( currentLine <= PRE_TILEMAP_DEF_LINE_COUNT )
            {
                std::getline( file, lineBuffer[currentLine - 1] );

                currentLine++ ;
            }

            _tilesetPath   = lineBuffer[0] ;
            _tileSize.x    = std::stoi( lineBuffer[1] ) ;
            _tileSize.y    = std::stoi( lineBuffer[2] ) ;
            _tilemapSize.x = std::stoi( lineBuffer[3] ) ;
            _tilemapSize.x = std::stoi( lineBuffer[4] ) ;

            //Ensure file has correct number of lines (PRE_TILEMAP_DEF_LINE_COUNT + tilemapSize.y)
            if ( lineCount == PRE_TILEMAP_DEF_LINE_COUNT + _tilemapSize.y )
                return true ;
        }

        return false ;
    }

    bool TileMap::createTileMap()
    {
        if ( _tileset.loadFromFile( _tilesetPath ) )
            return false ;

        //Resize vertex array to fit map size
        _vertices.setPrimitiveType( sf::Quads ) ;
        _vertices.resize( _tilemapSize.x * _tilemapSize.y * 4 ) ;

        //Populate vertex array w/ one quad per tile
        for ( unsigned int i = 0 ; i < _tilemapSize.x ; i++ )
        {
            for ( unsigned int j = 0 ; j < _tilemapSize.y ; j++ )
            {
                //int tileNumber = _tileData[i + j * _tilemapSize.x] ;
                int tileNumber = _tileData( i, j ) ;

                //Find uv coordinate
                int tu = tileNumber % ( _tileset.getSize().x / _tileSize.x ) ;
                int tv = tileNumber / ( _tileset.getSize().x / _tileSize.x ) ;

                sf::Vertex* quad = &_vertices[( i + j * _tilemapSize.x ) * 4] ;

                //Define 4 positional coordinates
                quad[0].position = sf::Vector2f(   i       * _tileSize.x,   j       * _tileSize.y ) ;
                quad[1].position = sf::Vector2f( ( i + 1 ) * _tileSize.x,   j       * _tileSize.y ) ;
                quad[2].position = sf::Vector2f( ( i + 1 ) * _tileSize.x, ( j + 1 ) * _tileSize.y ) ;
                quad[3].position = sf::Vector2f(   i       * _tileSize.x, ( j + 1 ) * _tileSize.y ) ;

                //Define 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(   tu       * _tileSize.x,   tv       * _tileSize.y ) ;
                quad[1].texCoords = sf::Vector2f( ( tu + 1 ) * _tileSize.x,   tv       * _tileSize.y ) ;
                quad[2].texCoords = sf::Vector2f( ( tu + 1 ) * _tileSize.x, ( tv + 1 ) * _tileSize.y ) ;
                quad[3].texCoords = sf::Vector2f(   tu       * _tileSize.x, ( tv + 1 ) * _tileSize.y ) ;
            }
        }

        return true ;
    }
}}