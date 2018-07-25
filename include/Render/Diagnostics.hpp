//
// Created by Peter Senyszyn on 7/24/18.
//

#ifndef SHOCKENGINE_DIAGNOSTICS_HPP
#define SHOCKENGINE_DIAGNOSTICS_HPP

#include <SFML/Graphics/Text.hpp>

#include "RenderedObject.hpp"
#include "../Resource/ResourceHolder.hpp"
#include "../Resource/ResourceIdentifiers.hpp"

namespace Shock
{
namespace Render
{
    //Shows diagnostic info like FPS, current state, etc
    class Diagnostics : public RenderedObject
    {
    private:
        enum class ScreenPosition
        {
            TOP_LEFT,
            TOP_RIGHT,
            BOTTOM_LEFT,
            BOTTOM_RIGHT
        } ;

    private:
        ScreenPosition _screenPosition ;

        sf::Text _fpsText ;
        sf::Time _updateTime ;
        std::size_t _numFrames ;

    public:
        Diagnostics( Resource::ResourceHolder<sf::Font, Resource::Fonts>& resourceHolder ) ;

        void handleEvent( Input::InputManager& inputManager ) override ;
        void update( sf::Time dt ) override ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) const override ;
    } ;
}}

#endif //SHOCKENGINE_DIAGNOSTICS_HPP