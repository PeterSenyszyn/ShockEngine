//
// Created by petersenyszyn on 4/7/19.
//

#include "../../include/Game/Entity.hpp"

namespace Shock
{
namespace Game
{
    ///From RenderedObject
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Entity::handleEvent( Input::InputManager& inputManager )
    {

    }

    void Entity::update( sf::Time dt )
    {

    }

    void Entity::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {

    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    Entity::Ptr Entity::create()
    {
        return std::make_unique<T>() ;
    }

    void Entity::addComponent()
    {

    }
}}