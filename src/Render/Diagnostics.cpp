//
// Created by Peter Senyszyn on 7/24/18.
//

#include "../../include/Render/Diagnostics.hpp"
#include "../../include/Core/StateStack.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

namespace Shock
{
namespace Render
{
    Diagnostics::Diagnostics( Core::ContextBuffer& contextBuffer ) :
    _contextBufferContext( &contextBuffer ),
    _screenPosition( ScreenPosition::TOP_LEFT )
    {
        sf::Font& font = _contextBufferContext->fontHolder->get( Resource::Fonts::Default ) ;

        _fpsText.setFont( font ) ;
        _fpsText.setString( "FPS: " ) ;
        _fpsText.setCharacterSize( 20u ) ;
        _fpsText.setFillColor( sf::Color::Green ) ;

        _numRenderedObjectsText.setFont( font ) ;
        _numRenderedObjectsText.setString( "RO count: " ) ;
        _numRenderedObjectsText.setCharacterSize( 20u ) ;
        _numRenderedObjectsText.setFillColor( sf::Color::Green ) ;
    }

    void Diagnostics::handleEvent( Input::InputManager& inputManager )
    {
        if ( inputManager.keyActive( Input::KAI::FPRESS ) )
        {
            setEnabled( !isEnabled() ) ;
        }
    }

    void Diagnostics::update( sf::Time dt )
    {
        switch ( _screenPosition )
        {
            case ScreenPosition::TOP_LEFT:
            {
                _fpsText.setPosition( 0.f, 0.f ) ;
                _numRenderedObjectsText.setPosition( 0.f, _fpsText.getPosition().y + 20.f ) ;

                break ;
            }

            case ScreenPosition::TOP_RIGHT:
            {
                break ;
            }

            case ScreenPosition::BOTTOM_LEFT:
            {
                break ;
            }

            case ScreenPosition::BOTTOM_RIGHT:
            {
                break ;
            }
        }

        //FPS counting
        _updateTime += dt ;
        _numFrames += 1 ;

        if ( _updateTime >= sf::seconds( 1.0f ) )
        {
            _fpsText.setString( "FPS: " + std::to_string( _numFrames ) ) ;

            _updateTime -= sf::seconds( 1.0f ) ;
            _numFrames = 0 ;
        }

        _numRenderedObjectsText.setString( "RO count: " + std::to_string( _contextBufferContext->renderedObjectManager->getNumRenderedObjects() ) ) ;
    }

    void Diagnostics::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {
        target.draw( _fpsText, states ) ;
        target.draw( _numRenderedObjectsText, states ) ;
    }
}}