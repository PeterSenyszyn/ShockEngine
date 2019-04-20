//
// Created by petersenyszyn on 4/7/19.
//

#ifndef SHOCKENGINE_WORLD_HPP
#define SHOCKENGINE_WORLD_HPP

#include "../Core/ContextBuffer.hpp"
#include "Instance.hpp"
#include "Player.hpp"

namespace Shock
{
namespace Game
{
    class World
    {
    public:
        World( Core::ContextBuffer* context ) ;

        void handleEvent( Input::InputManager& inputManager ) ;
        void update( sf::Time dt ) ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) ;

        void addInstance( Instance::Ptr instance ) ;

        Player& getPlayer() ;

    private:
        void cleanInstances( std::vector<Instance::Ptr>::iterator iter ) ;

    private:
        Core::ContextBuffer* _context ;

        std::vector<Instance::Ptr> _instances ;

        Player _player ;
    } ;
}}

#endif //SHOCKENGINE_WORLD_HPP