//
// Created by Peter Senyszyn on 7/24/18.
//

#include "../../include/States/GameState.hpp"

namespace Shock
{
namespace States
{
    GameState::GameState( Core::StateStack& stack, Context context ) :
    Core::State( stack, context )
    {
    }

    bool GameState::handleEvent( const sf::Event &event )
    {
        Input::InputManager& inputManager = *getContext().buffer->inputManager ;

        return false;
    }

    bool GameState::update( sf::Time dt )
    {
        return false;
    }

    void GameState::draw()
    {
        sf::RenderWindow& window = *getContext().buffer->window ;

        //window.setView( window.getDefaultView() ) ;

        /*sf::CircleShape shape ;
        shape.setFillColor( sf::Color::Blue ) ;
        shape.setRadius( 40.f ) ;
        shape.setPosition( 200, 200 ) ;

        window.draw( shape ) ;*/
    }
}}