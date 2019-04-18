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

#include "RenderedObject.hpp"
#include "../Utilities/Math/Matrix.hpp"

namespace Shock
{
namespace Render
{
    class TileMap : public RenderedObject
    {
    public:
        TileMap() ;

        //Extension .stm (Shock Tile Map)
        bool load( const std::string& tilemapPath ) ;

        void handleEvent( Input::InputManager& inputManager ) override ;
        void update( sf::Time dt ) override ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) const override ;

    private:
        //Number of lines there should be in file BEFORE tile data
        const unsigned int PRE_TILEMAP_DEF_LINE_COUNT = 5 ;

    private:
        sf::VertexArray          _vertices ;
        sf::Texture              _tileset ;

        std::string              _tilesetPath ;
        sf::Vector2i             _tileSize ;
        sf::Vector2i             _tilemapSize ;
        Utils::Matrix2D<int>     _tileData ;

    private:
        bool analyzeFile( std::ifstream& file ) ;
        bool createTileMap() ;
    } ;
}}

#endif //SHOCKENGINE_TILEMAP_HPP