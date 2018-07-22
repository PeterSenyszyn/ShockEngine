//
// Created by Peter Senyszyn on 7/21/18.
//

#include "../../include/Core/Application.hpp"

#include <SFML/Window/Event.hpp>

namespace Shock
{
namespace Core
{
    ////////////////////////////////////////////////////////////////////////////////////////

    void Application::registerStates()
    {
        //_stateStack.registerState
    }

    ////////////////////////////////////////////////////////////////////////////////////////

    Application::Application() :
    _stateStack( State::Context() ),
    _maxFps( 60 )
    {
        sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close ;

        _renderWindow.create( sf::VideoMode( 800, 600 ), "Shock Engine",
                              style ) ;

        _renderWindow.resetGLStates() ;
        _renderWindow.setKeyRepeatEnabled( false ) ;
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

            if ( event.type == sf::Event::Closed )
            { quit(); }
        }
    }

    void Application::update( sf::Time dt )
    {

    }

    void Application::render()
    {
        _renderWindow.clear() ;

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