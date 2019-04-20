//
// Created by petersenyszyn on 4/7/19.
//

#ifndef SHOCKENGINE_INSTANCE_HPP
#define SHOCKENGINE_INSTANCE_HPP

#include <vector>

#include "Entity.hpp"
#include "../Render/TileMap.hpp"
#include "Player.hpp"

/*
 * An Instance represents the "level" as you could imagine in the game.
 */

namespace Shock::Game
{
    class Instance
    {
    public:
        typedef std::unique_ptr<Instance> Ptr ;

    public:
        explicit Instance( Player* playerContext ) ;

        void handleEvent( Input::InputManager& inputManager ) ;
        void update( sf::Time dt ) ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) ;

        void addTilemap( const std::string& mapPath ) ;

        const void markForDeletion( bool value ) ;
        const bool needsDelete() const ;

    private:
        //Instances are designed to live within World indefinitely, so when we want to clean up
        //we'll mark this flag
        bool _delete ;

        Player* _playerContext ;

        std::vector<Entity::Ptr> _entities ;

        std::unique_ptr<Render::TileMap> _tilemap ;
    } ;
}

#endif //SHOCKENGINE_INSTANCE_HPP