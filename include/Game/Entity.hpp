//
// Created by petersenyszyn on 4/7/19.
//

#ifndef SHOCKENGINE_ENTITY_HPP
#define SHOCKENGINE_ENTITY_HPP

#include <memory>

#include <SFML/Window/Event.hpp>

#include "../Render/RenderedObject.hpp"
#include "Components/Component.hpp"

namespace Shock::Game
{
    //Designed to represent in-game rendered objects
    //Examples: player(s), enemies, AI's, isolated objects (like rocks) etc
    class Entity : public Render::RenderedObject
    {
    public:
        typedef std::unique_ptr<Entity> Ptr ;

        explicit Entity( sf::RenderTarget* targetContext ) ;
        ~Entity() override = default ;

        ///From RenderedObject
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void handleEvent( Input::InputManager& inputManager ) override ;
        void update( sf::Time dt ) override ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) const override ;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void           addComponent( Component::Ptr component ) ;
        Component::Ptr getComponent( const std::string& name ) ;

        virtual void setCoords() = 0 ;

        const sf::Vector2f&  getWorldCoords() ;
        const sf::FloatRect& getBounds() ;
        sf::Vector2f         getCenterCoords() ;

    protected:
        sf::Vector2f  _worldCoords ;
        sf::FloatRect _bounds ;

        sf::RenderTarget* _targetContext ;

    private:
        std::vector<Component::Ptr> _components ;
    } ;
}

#endif //SHOCKENGINE_ENTITY_HPP