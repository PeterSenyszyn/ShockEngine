//
// Created by Peter Senyszyn on 7/24/18.
//

#include "../../include/States/GameState.hpp"
#include <SFML/Graphics/CircleShape.hpp>

namespace Shock::States
{
    GameState::GameState( Core::StateStack& stack, Context context ) :
    Core::State( stack, context ),
    _world( context.buffer )
    {
        using namespace Game ;
        //Create first instance
        Instance::Ptr instance = std::make_unique<Instance>( &_world.getPlayer()) ;
        instance->addTilemap( "/home/petersenyszyn/CLionProjects/ShockEngine/mapdata/test.stm" ) ;
        _world.addInstance( std::move( instance ) ) ;
    }

    bool GameState::handleEvent( const sf::Event& event )
    {
        Input::InputManager& inputManager = *getContext().buffer->inputManager ;

        _world.handleEvent( inputManager ) ;

        return false;
    }

    bool GameState::update( sf::Time dt )
    {
        _world.update( dt ) ;

        return false;
    }

    void GameState::draw()
    {
        sf::RenderWindow& window = *getContext().buffer->window ;

        _world.render( window, sf::RenderStates() ) ;
    }
}