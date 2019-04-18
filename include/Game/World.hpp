//
// Created by petersenyszyn on 4/7/19.
//

#ifndef SHOCKENGINE_WORLD_HPP
#define SHOCKENGINE_WORLD_HPP

#include "../Core/ContextBuffer.hpp"
#include "InstanceManager.hpp"

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

    private:
        Core::ContextBuffer* _context ;

        InstanceManager _instanceManager ;
    } ;
}}

#endif //SHOCKENGINE_WORLD_HPP