//
// Created by Peter Senyszyn on 7/21/18.
//

#ifndef SHOCKENGINE_APPLICATION_HPP
#define SHOCKENGINE_APPLICATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Desktop.hpp>
#include <SFGUI/Window.hpp>
#include <SFGUI/Label.hpp>
#include <SFGUI/Button.hpp>
#include <SFGUI/Box.hpp>

#include "StateStack.hpp"
#include "../Input/InputManager.hpp"
#include "../Resource/ResourceHolder.hpp"
#include "../Resource/ResourceIdentifiers.hpp"
#include "../Render/RenderedObjectManager.hpp"

namespace Shock
{
namespace Core
{
    class Application
    {
    private:
        void registerStates() ;
        void loadResources() ;
        void loadRenderedObjects() ;
        void initGui() ;

    private:
        sf::RenderWindow _renderWindow ;

        //Finite state machine
        StateStack _stateStack ;

        //Context buffer for states
        ContextBuffer _contextBuffer ;

        //Engine managers
        Input::InputManager _inputManager ;
        Render::RenderedObjectManager _renderedObjectManager ;

        //Resources
        Resource::ResourceHolder<sf::Texture, Resource::Textures> _textureHolder ;
        Resource::ResourceHolder<sf::Font, Resource::Fonts>       _fontHolder ;

        //SFGUI
        sfg::SFGUI _sfgui ;
        sfg::Desktop _desktop ;

        float _maxFps ;

    public:
        Application() ;

        void processInput() ;
        void update( sf::Time dt ) ;
        void render() ;

        const bool isRunning() const ;
        const void quit() ;

        const float getMaxFps() const ;
        const void setMaxFps( const float value ) ;
    } ;
}}

#endif //SHOCKENGINE_APPLICATION_HPP