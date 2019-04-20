//
// Created by petersenyszyn on 4/12/19.
//

#ifndef SHOCKENGINE_COMPONENT_HPP
#define SHOCKENGINE_COMPONENT_HPP

#include <string>
#include <functional>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "../../Input/InputManager.hpp"

namespace Shock::Game
{
    class Entity ;

    class Component
    {
    public:
        virtual ~Component() = default ;

        //Component logic goes into these methods
        //Not pure virtual because not all components will need each type (i.e movement doesn't require rendering)
        virtual void handleEvent( Input::InputManager& inputManager ) {}
        virtual void update( sf::Time dt ) {}
        virtual void render( sf::RenderTarget& target, sf::RenderStates states ) const {}

        const void setName( const std::string& name )
        { _name = name ; }

        const std::string& getName() const
        { return _name ; }

        Entity* getParentEntity()
        { return _parentEntity ; }

    protected:
        explicit Component( std::string name, Entity* parentEntity ) :
            _name( std::move( name ) ),
           _parentEntity( _parentEntity = parentEntity ) {}

    private:
        std::string _name ;

        Entity* _parentEntity ;
    } ;
}

#endif //SHOCKENGINE_COMPONENT_HPP