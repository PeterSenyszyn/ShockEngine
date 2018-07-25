//
// Created by Peter Senyszyn on 7/21/18.
//

#ifndef SHOCKENGINE_INPUTMANAGER_HPP
#define SHOCKENGINE_INPUTMANAGER_HPP

#include <Thor/Input/ActionMap.hpp>

#include "../../include/Input/Manager.hpp"
#include "KeyActionIds.hpp"

namespace Shock
{
namespace Input
{
    class InputManager : public Core::Manager
    {
    public: typedef thor::ActionMap<Input::KAI> KeyboardMap ;
    private:
        KeyboardMap _keyboardMap ;

    private:
        void initKeys() ;

    public:
        InputManager() ;

        void processInput() override ;

        ///////////////////////////////////////////

        void clearEvents() ;
        void pushEvent( const sf::Event& event ) ;

        ///////////////////////////////////////////

        bool keyActive( Shock::Input::KAI key ) ;
    } ;
}}

#endif //SHOCKENGINE_INPUTMANAGER_HPP