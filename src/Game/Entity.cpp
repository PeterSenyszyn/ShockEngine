//
// Created by petersenyszyn on 4/7/19.
//

#include "../../include/Game/Entity.hpp"

namespace Shock::Game
{
    ///From RenderedObject
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Entity::handleEvent( Input::InputManager& inputManager )
    {
        for ( const auto& iter : _components )
            iter->handleEvent( inputManager ) ;
    }

    void Entity::update( sf::Time dt )
    {
        for ( const auto& iter : _components )
            iter->update( dt ) ;
    }

    void Entity::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {
        for ( const auto& iter : _components )
            iter->render( target, states ) ;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    Entity::Ptr Entity::create()
    {
        return std::make_unique<T>() ;
    }

    void Entity::addComponent( std::unique_ptr<Component> component )
    {
        _components.push_back( std::move( component ) ) ;
    }
}