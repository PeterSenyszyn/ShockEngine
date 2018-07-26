//
// Created by Peter Senyszyn on 7/21/18.
//

#include "../../include/Core/Application.hpp"

#include "../../include/States/GameState.hpp"
#include "../../include/States/PauseState.hpp"

#include "../../include/Render/Diagnostics.hpp"

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

    void Application::loadResources()
    {
        using namespace Resource ;

        _fontHolder.load( Fonts::Default, "assets/Prototype.ttf" ) ;
    }

    void Application::loadRenderedObjects()
    {
        using namespace Render ;

        _renderedObjectManager.addRenderedObject( "Diagnostics",
                                                  std::unique_ptr<Diagnostics>( new Diagnostics( _contextBuffer ) ) ) ;
    }

    ////////////////////////////////////////////////////////////////////////////////////////

    Application::Application() :
    _stateStack( State::Context( _contextBuffer ) ),
    _contextBuffer( _renderWindow, _stateStack, _inputManager, _renderedObjectManager,
                    _textureHolder, _fontHolder ),
    _maxFps( 60 )
    {
        sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close ;

        _renderWindow.create( sf::VideoMode( 800, 600 ), "Shock Engine",
                              style ) ;

        _renderWindow.resetGLStates() ;
        _renderWindow.setKeyRepeatEnabled( false ) ;

        registerStates() ;
        loadResources() ;
        loadRenderedObjects() ;

        _stateStack.pushState( StateIds::Game ) ;
    }

    ////////////////////////////////////////////////////////////////////////////////////////

    void Application::processInput()
    {
        sf::Event event ;

        _inputManager.clearEvents() ;

        while ( _renderWindow.pollEvent( event ) )
        {
            _inputManager.pushEvent( event ) ;

            _inputManager.processInput() ;

            _stateStack.handleEvent( event ) ;

            if ( event.type == sf::Event::Closed )
            { quit(); }
        }

        _renderedObjectManager.handleEvent( _inputManager ) ;
    }

    void Application::update( sf::Time dt )
    {
        _stateStack.update( dt ) ;

        _renderedObjectManager.update( dt ) ;
    }

    void Application::render()
    {
        _renderWindow.clear() ;

        _stateStack.draw() ;

        _renderedObjectManager.draw( _renderWindow ) ;

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

    const void Application::setMaxFps( const float value )
    { _maxFps = value ; }

    ////////////////////////////////////////////////////////////////////////////////////////
}}