//
// Created by Peter Senyszyn on 7/24/18.
//

#include "../../include/States/GameState.hpp"
#include <SFML/Graphics/CircleShape.hpp>

namespace Shock
{
namespace States
{
    GameState::GameState( Core::StateStack& stack, Context context ) :
    Core::State( stack, context ),
    _world( context.buffer )
    {
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

        /*sf::CircleShape shape ;
        shape.setFillColor( sf::Color::Blue ) ;
        shape.setRadius( 40.f ) ;
        shape.setPosition( 200, 200 ) ;

        window.draw( shape ) ;*/
    }
}}