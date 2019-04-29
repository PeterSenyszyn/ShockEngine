//
// Created by petersenyszyn on 4/7/19.
//

#include "../../include/Game/World.hpp"

namespace Shock
{
namespace Game
{
    World::World( Core::ContextBuffer* context ) :
    _context( context ),
    _player( &_context->textureHolder->get( Resource::Textures::Player ), context->window )
    {

    }

    void World::handleEvent( Input::InputManager& inputManager )
    {
        for ( const auto& iter : _instances )
            iter->handleEvent( inputManager ) ;

        _player.handleEvent( inputManager ) ;
    }

    void World::update( sf::Time dt )
    {
        for ( auto iter = _instances.begin() ; iter != _instances.end() ; iter++ )
        {
            cleanInstances( iter ) ;

            (*iter)->update( dt ) ;
        }

        _player.update( dt ) ;
    }

    void World::render( sf::RenderTarget& target, sf::RenderStates states )
    {
        //FIXME only render when active
        for ( const auto& iter : _instances )
            iter->render( target, states ) ;

        _player.render( target, states ) ;
    }

    void World::addInstance( Instance::Ptr instance )
    {
        _instances.push_back( std::move( instance ) ) ;
    }

    Player& World::getPlayer()
    { return _player ; }

    void World::cleanInstances( std::vector<Instance::Ptr>::iterator iter )
    {
        if ( (*iter)->needsDelete() )
            _instances.erase( iter ) ;
    }
}}