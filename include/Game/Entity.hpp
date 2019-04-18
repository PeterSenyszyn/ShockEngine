//
// Created by petersenyszyn on 4/7/19.
//

#ifndef SHOCKENGINE_ENTITY_HPP
#define SHOCKENGINE_ENTITY_HPP

#include <memory>

#include <SFML/Window/Event.hpp>

#include "../Render/RenderedObject.hpp"

namespace Shock
{
namespace Game
{
    //Designed to represent in-game rendered objects
    //Examples: player(s), enemies, AI's, isolated objects (like rocks) etc
    class Entity : public Render::RenderedObject
    {
    public:
        typedef std::unique_ptr<Entity> Ptr ;

        ~Entity() override = default ;

        ///From RenderedObject
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void handleEvent( Input::InputManager& inputManager ) override ;
        void update( sf::Time dt ) override ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) const override ;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        template <class T> static Ptr create() ;

        void addComponent() ;

    private:

    } ;
}}

#endif //SHOCKENGINE_ENTITY_HPP