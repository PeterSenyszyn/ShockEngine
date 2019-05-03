//
// Created by petersenyszyn on 4/30/19.
//

#ifndef SHOCKENGINE_PROCEDURALTILEMAP_HPP
#define SHOCKENGINE_PROCEDURALTILEMAP_HPP

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Map.hpp"
#include "Tile.hpp"
#include "../Game/Player.hpp"

namespace Shock::Render
{
    class ProceduralTileMap : public Map
    {
    public:
        ProceduralTileMap( Game::Player* playerContext ) ;

        void handleEvent( Input::InputManager& inputManager ) override ;
        void update( sf::Time dt ) override ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) const override ;

        void init( const std::string& tilesheetPath, sf::Vector2u tileSize,
                   sf::Vector2u chunkSize ) ;
    private:
        void generateInitialMap() ;

        void generateChunk( sf::Vector2f topLeftWorldCoord ) ;

    private:
        struct Chunk
        {
            typedef std::shared_ptr<Chunk> Ptr ;

            Chunk( sf::Vector2u size ) ;

            std::vector<Tile> tiles ;
            sf::VertexArray vertices ;
        } ;

    private:
        Game::Player* _playerContext ;

        sf::Texture _tileset ;

        sf::Vector2u _tileSize ;
        sf::Vector2u _chunkSize ;

        bool _renderingNewChunk ;

        std::vector<Chunk::Ptr> _chunks ; //all chunks, inclusive of ones being rendered
        std::vector<Chunk::Ptr> _renderedChunks ; //just so we don't have to iterate over all of _chunks

        std::vector<int> _collidableTileIds ;
    } ;
}


#endif //SHOCKENGINE_PROCEDURALTILEMAP_HPP
