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

        //_fontHolder.load( Fonts::Default, "/home/petersenyszyn/CLionProjects/ShockEngine/assets/Prototype.ttf" ) ;
        _fontHolder.load( Fonts::Default, "/Users/petersenyszyn/Documents/ShockEngine/assets/Prototype.ttf" ) ;
    }

    void Application::loadRenderedObjects()
    {
        using namespace Render ;

        _renderedObjectManager.addRenderedObject( "Diagnostics",
                                                  std::make_unique<Diagnostics>( _contextBuffer ) ) ;
    }

    void Application::initGui()
    {
        auto font = std::make_shared<sf::Font>( _fontHolder.get( Resource::Fonts::Default ) ) ;

        _desktop.GetEngine().GetResourceManager().SetDefaultFont( font ) ;

        auto window = sfg::Window::Create() ;
        window->SetTitle( "test" ) ;

        _desktop.Add( window ) ;

        _desktop.Refresh() ;
    }

    ////////////////////////////////////////////////////////////////////////////////////////

    Application::Application() :
    _stateStack( State::Context( _contextBuffer ) ),
    _contextBuffer( _renderWindow, _stateStack, _inputManager, _renderedObjectManager,
                    _textureHolder, _fontHolder ),
    _maxFps( 60 )
    {
        sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close ;

        sf::ContextSettings settings ;
        settings.majorVersion = 4 ;
        settings.minorVersion = 1 ;

        _renderWindow.create( sf::VideoMode( 1920, 1080 ), "Shock Engine",
                              style, settings ) ;

        settings = _renderWindow.getSettings() ;

        std::cout << "Shock Engine is running OpenGL version: " << settings.majorVersion << "." << settings.minorVersion << std::endl ;

        _renderWindow.resetGLStates() ;
        _renderWindow.setKeyRepeatEnabled( false ) ;
        _renderWindow.setVerticalSyncEnabled( true ) ;

        registerStates() ;
        loadResources() ;
        loadRenderedObjects() ;
        initGui() ;

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

            _desktop.HandleEvent( event ) ;

            if ( event.type == sf::Event::Closed )
            { quit(); }
        }

        _renderedObjectManager.handleEvent( _inputManager ) ;
    }

    void Application::update( sf::Time dt )
    {
        _stateStack.update( dt ) ;

        _renderedObjectManager.update( dt ) ;

        _desktop.Update( dt.asSeconds() ) ;
    }

    void Application::render()
    {
        _renderWindow.clear( sf::Color::Black ) ;

        _stateStack.draw() ;

        _renderedObjectManager.draw( _renderWindow ) ;

        _renderWindow.setView( _renderWindow.getDefaultView() ) ;

        _sfgui.Display( _renderWindow ) ;

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