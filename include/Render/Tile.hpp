//
// Created by petersenyszyn on 4/30/19.
//

#ifndef SHOCKENGINE_TILE_HPP
#define SHOCKENGINE_TILE_HPP

#include <SFML/Graphics/Rect.hpp>

namespace Shock::Render
{
    struct Tile //Engine abstraction to make manipulation easier w/ game logic
    {
        Tile( int tileId, sf::FloatRect bounds ) :
        tileId( tileId ), bounds( bounds ) {}

        int           tileId ;
        sf::FloatRect bounds ;
    } ;
}


#endif //SHOCKENGINE_TILE_HPP