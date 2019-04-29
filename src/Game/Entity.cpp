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
        this->setCoords() ;

        for ( const auto& iter : _components )
            iter->update( dt ) ;
    }

    void Entity::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {
        for ( const auto& iter : _components )
            iter->render( target, states ) ;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Entity::Entity( sf::RenderTarget* targetContext ) :
    _targetContext( targetContext )
    {
    }

    void Entity::addComponent( Component::Ptr component )
    {
        _components.push_back( component ) ;
    }

    Component::Ptr Entity::getComponent( const std::string& name )
    {
        for ( const auto& iter : _components )
        {
            if ( iter->getName() == name )
                return iter ;
        }

        return nullptr ;
    }

    const sf::Vector2f& Entity::getWorldCoords()
    { return _worldCoords ; }

    const sf::FloatRect& Entity::getBounds()
    { return _bounds ; }

    sf::Vector2f Entity::getCenterCoords()
    {
        return sf::Vector2f( _worldCoords.x + ( _bounds.width / 2.f ),
                             _worldCoords.y + ( _bounds.height / 2.f ) ) ;
    }
}