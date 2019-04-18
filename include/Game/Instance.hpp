//
// Created by petersenyszyn on 4/7/19.
//

#ifndef SHOCKENGINE_INSTANCE_HPP
#define SHOCKENGINE_INSTANCE_HPP

#include <vector>

#include "Entity.hpp"

/*
 * An Instance represents the "level" as you could imagine in the game.
 */

namespace Shock
{
namespace Game
{
    class Instance
    {
    public:
        typedef std::unique_ptr<Instance> Ptr ;

    public:
        void handleEvent( Input::InputManager& inputManager ) ;
        void update( sf::Time dt ) ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) ;

        const void markForDeletion( bool value ) ;
        const bool needsDelete() const ;

    private:
        //Instances are designed to live within InstanceManager indefinitely, so when we want to clean up
        //we'll mark this flag
        bool _delete ;

        std::vector<Entity::Ptr> _entities ;

    private:
        explicit Instance() ;

        //We want Instance header declaration open to import (instead of hidden within InstanceManager)
        //but don't want any facility to instantiate Instance's from outside of InstanceManager
        friend class InstanceManager ;
    } ;
}}

#endif //SHOCKENGINE_INSTANCE_HPP