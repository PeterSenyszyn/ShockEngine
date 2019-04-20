//
// Created by Peter Senyszyn on 7/21/18.
//

#ifndef SHOCKENGINE_INPUTMANAGER_HPP
#define SHOCKENGINE_INPUTMANAGER_HPP

#include <Thor/Input/ActionMap.hpp>

#include "../Core/Manager.hpp"
#include "KeyActionIds.hpp"

namespace Shock
{
namespace Input
{
    class InputManager : public Core::Manager
    {
    public:
        InputManager() ;

        ///////////////////////////////////////////

        void clearEvents() ;
        void pushEvent( const sf::Event& event ) ;

        ///////////////////////////////////////////

        bool keyActive( Shock::Input::KAI key ) ;

    private:
        void initKeys() ;

    private:
        thor::ActionMap<Input::KAI> _keyboardMap ;
    } ;
}}

#endif //SHOCKENGINE_INPUTMANAGER_HPP