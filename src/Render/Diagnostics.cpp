//
// Created by Peter Senyszyn on 7/24/18.
//

#include "../../include/Render/Diagnostics.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

namespace Shock
{
namespace Render
{
    Diagnostics::Diagnostics( Resource::ResourceHolder<sf::Font, Resource::Fonts>& resourceHolder ) :
    _screenPosition( ScreenPosition::TOP_LEFT )
    {
        _fpsText.setFont( resourceHolder.get( Resource::Fonts::Default ) ) ;
        _fpsText.setPosition( 0.f, 0.f ) ;
        _fpsText.setCharacterSize( 12u ) ;
    }

    void Diagnostics::handleEvent( Input::InputManager& inputManager )
    {
        if ( inputManager.keyActive( Input::KAI::FPRESS ) )
        {
            std::cout << "fpress" << std::endl ;
            setEnabled( !isEnabled() ) ;
        }
    }

    void Diagnostics::update( sf::Time dt )
    {
        _updateTime += dt ;
        _numFrames += 1 ;

        if ( _updateTime >= sf::seconds( 1.0f ) )
        {
            _fpsText.setString( "FPS: " + std::to_string( _numFrames ) ) ;

            _updateTime -= sf::seconds( 1.0f ) ;
            _numFrames = 0 ;
        }

        switch ( _screenPosition )
        {
            case ScreenPosition::TOP_LEFT:
            {
                _fpsText.setPosition( 0.f, 0.f ) ;

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
    }

    void Diagnostics::render( sf::RenderTarget& target, sf::RenderStates states ) const
    {
        target.draw( _fpsText, states ) ;
    }
}}