//
// Created by Peter Senyszyn on 7/21/18.
//

#ifndef SHOCKENGINE_APPLICATION_HPP
#define SHOCKENGINE_APPLICATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include "StateStack.hpp"
#include "../Input/InputManager.hpp"

namespace Shock
{
namespace Core
{
    class Application
    {
    private:
        void registerStates() ;

    private:
        sf::RenderWindow _renderWindow ;

        //Finite state machine
        StateStack _stateStack ;

        //Context buffer for states
        ContextBuffer _contextBuffer ;

        //Engine managers
        Input::InputManager _inputManager ;

        float _maxFps ;

    public:
        Application() ;

        void processInput() ;
        void update( sf::Time dt ) ;
        void render() ;

        const bool isRunning() const ;
        const void quit() ;

        const float getMaxFps() const ;
        const float setMaxFps( const float value ) ;
    } ;
}}

#endif //SHOCKENGINE_APPLICATION_HPP