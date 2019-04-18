//
// Created by petersenyszyn on 4/7/19.
//

#ifndef SHOCKENGINE_INSTANCEMANAGER_HPP
#define SHOCKENGINE_INSTANCEMANAGER_HPP

#include "Instance.hpp"

/*
 * InstanceManager exists to allow ShockEngine to hold several "levels" in memory if needed.
 * For example, a certain part of the world still needs to be updated but the associated objects
 * should not be rendered.
 */

namespace Shock
{
namespace Game
{
    class InstanceManager
    {
    public:
        void handleEvent( Input::InputManager& inputManager ) ;
        void update( sf::Time dt ) ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) ;

        void addInstance( Instance::Ptr instance ) ;

    private:
        void cleanInstances( std::vector<Instance::Ptr>::iterator iter ) ;

    private:
        std::vector<Instance::Ptr> _instances ;
    } ;
}}

#endif //SHOCKENGINE_INSTANCEMANAGER_HPP
