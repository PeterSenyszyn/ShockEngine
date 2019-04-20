//
// Created by petersenyszyn on 4/20/19.
//

#ifndef SHOCKENGINE_MAP_HPP
#define SHOCKENGINE_MAP_HPP

#include "RenderedObject.hpp"

namespace Shock::Render
{
    class Map : public RenderedObject
    {
    public:
        Map() = default ;
        ~Map() override = default ;

        void handleEvent( Input::InputManager& inputManager ) override ;
        void update( sf::Time dt ) override ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) const override ;

        const void setCollisionPoints( std::vector<sf::FloatRect> collisionPoints ) ;
        const void addCollisionPoint( sf::FloatRect& collisionPoint ) ;
        std::vector<sf::FloatRect>& getCollisionPoints() ;

    private:
        std::vector<sf::FloatRect> _collisionPoints ;
    } ;
}

#endif //SHOCKENGINE_MAP_HPP