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

namespace Shock
{
namespace Game
{
    //Interface
    class Component
    {
    public:
        virtual ~Component() = default ;

        //Component logic goes into these methods
        //Not pure virtual because not all components will need each type (i.e movement doesn't require rendering)
        virtual void handleEvent( Input::InputManager& inputManager ) {}
        virtual void update( sf::Time dt ) {}
        virtual void render( sf::RenderTarget& target, sf::RenderStates states ) const {}

        virtual const void setName( const std::string& name )
        { _name = name ; }

        virtual const std::string& getName() const
        { return _name ; }

    protected:
        explicit Component( std::string name ) : _name( std::move( name ) ) {}

    private:
        std::string _name ;
    } ;
}}

#endif //SHOCKENGINE_COMPONENT_HPP