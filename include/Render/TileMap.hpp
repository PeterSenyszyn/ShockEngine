//
// Created by petersenyszyn on 4/6/19.
//

#ifndef SHOCKENGINE_TILEMAP_HPP
#define SHOCKENGINE_TILEMAP_HPP

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Map.hpp"
#include "../Utilities/Math/Matrix.hpp"

namespace Shock::Render
{
    class TileMap : public Map
    {
    public:
        TileMap() ;

        //Extension .stm (Shock Tile Map)
        bool load( const std::string& tilemapPath ) ;

        void handleEvent( Input::InputManager& inputManager ) override ;
        void update( sf::Time dt ) override ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) const override ;

        const sf::Vector2u& getTileMapSize() ;

    private:
        struct Tile //Engine abstraction to make manipulation easier w/ game logic
        {
            Tile( int tileId, sf::FloatRect bounds ) ;

            int           tileId ;
            sf::FloatRect bounds ;
        } ;

    private:
        //Number of lines there should be in file BEFORE tile data
        const unsigned int PRE_TILEMAP_DEF_LINE_COUNT = 6 ;

    private:
        sf::VertexArray          _vertices ;
        sf::Texture              _tileset ;

        std::string              _tilesetPath ;
        sf::Vector2u             _tileSize ;
        sf::Vector2u             _tilemapSizeTiles ;
        sf::Vector2u             _tilemapSize ;
        Utils::Matrix2D<int>     _tileData ;

        std::vector<Tile>        _tiles ;
        std::vector<int>         _collidableTileIds ;

    private:
        bool analyzeFile( std::ifstream& file ) ;
        bool createTileMap() ;
    } ;
}

#endif //SHOCKENGINE_TILEMAP_HPP