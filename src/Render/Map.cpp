//
// Created by petersenyszyn on 4/20/19.
//

#include "../../include/Render/Map.hpp"

namespace Shock::Render
{

    void Map::handleEvent( Input::InputManager& inputManager )
    {
    }

    void Map::update( sf::Time dt )
    {
    }

    void Map::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {
    }

    const void Map::setCollisionPoints( std::vector<sf::FloatRect> collisionPoints )
    { _collisionPoints = std::move( collisionPoints ) ; }

    const void Map::addCollisionPoint( sf::FloatRect& collisionPoint )
    { _collisionPoints.push_back( collisionPoint ) ; }

    std::vector<sf::FloatRect>& Map::getCollisionPoints()
    { return _collisionPoints ; }
}