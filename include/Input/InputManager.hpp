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
    private:
        thor::ActionMap<Shock::Input::KAI> _keyboardMap ;

    private:
        void initKeys() ;

    public:
        InputManager() ;

        virtual void processInput() ;

        ///////////////////////////////////////////

        void clearEvents() ;
        void pushEvent( const sf::Event& event ) ;

        ///////////////////////////////////////////

        bool keyActive( Shock::Input::KAI key ) ;
    } ;
}}

#endif //SHOCKENGINE_INPUTMANAGER_HPP