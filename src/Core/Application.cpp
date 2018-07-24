//
// Created by Peter Senyszyn on 7/21/18.
//

#include "../../include/Core/Application.hpp"

#include "../../include/States/GameState.hpp"
#include "../../include/States/PauseState.hpp"

#include <SFML/Window/Event.hpp>

namespace Shock
{
namespace Core
{
    ////////////////////////////////////////////////////////////////////////////////////////

    void Application::registerStates()
    {
        _stateStack.registerState<States::GameState>( StateIds::Game ) ;
    }

    ////////////////////////////////////////////////////////////////////////////////////////

    Application::Application() :
    _stateStack( State::Context( _contextBuffer ) ),
    _contextBuffer( _renderWindow, _inputManager ),
    _maxFps( 60 )
    {
        sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close ;

        _renderWindow.create( sf::VideoMode( 800, 600 ), "Shock Engine",
                              style ) ;

        _renderWindow.resetGLStates() ;
        _renderWindow.setKeyRepeatEnabled( false ) ;

        registerStates() ;

        _stateStack.pushState( StateIds::Game ) ;
    }

    ////////////////////////////////////////////////////////////////////////////////////////

    void Application::processInput()
    {
        sf::Event event ;

        _inputManager.clearEvents() ;

        while ( _renderWindow.pollEvent( event ) )
        {
            _inputManager.pushEvent( event );
            _inputManager.processInput();

            _stateStack.handleEvent( event ) ;

            if ( event.type == sf::Event::Closed )
            { quit(); }
        }
    }

    void Application::update( sf::Time dt )
    {
        _stateStack.update( dt ) ;
    }

    void Application::render()
    {
        _renderWindow.clear() ;

        _stateStack.draw() ;

        _renderWindow.setView( _renderWindow.getDefaultView() ) ;

        _renderWindow.display() ;
    }

    ////////////////////////////////////////////////////////////////////////////////////////

    const bool Application::isRunning() const
    { return _renderWindow.isOpen() ;}

    const void Application::quit()
    { _renderWindow.close() ; }

    ////////////////////////////////////////////////////////////////////////////////////////

    const float Application::getMaxFps() const
    { return _maxFps ; }

    const float Application::setMaxFps( const float value )
    { _maxFps = value ; }

    ////////////////////////////////////////////////////////////////////////////////////////
}}