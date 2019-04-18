//
// Created by Peter Senyszyn on 7/21/18.
//

#include "../../include/Input/InputManager.hpp"

#include <iostream>
namespace Shock
{
namespace Input
{
    InputManager::InputManager()
    {
        initKeys() ;
    }

    void InputManager::clearEvents()
    {
        _keyboardMap.clearEvents() ;
    }

    void InputManager::pushEvent( const sf::Event& event )
    {
        _keyboardMap.pushEvent( event ) ;
    }

    bool InputManager::keyActive( Shock::Input::KAI key )
    { return _keyboardMap.isActive( key ) ; }

    void InputManager::initKeys()
    {
        /*********************************************************************************************
        *****************************************PRESS***********************************************/

        //Alphabet (press)
        _keyboardMap[KAI::APRESS] = thor::Action( sf::Keyboard::A, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::BPRESS] = thor::Action( sf::Keyboard::B, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::CPRESS] = thor::Action( sf::Keyboard::C, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::DPRESS] = thor::Action( sf::Keyboard::D, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::EPRESS] = thor::Action( sf::Keyboard::E, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::FPRESS] = thor::Action( sf::Keyboard::F, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::GPRESS] = thor::Action( sf::Keyboard::G, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::HPRESS] = thor::Action( sf::Keyboard::H, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::IPRESS] = thor::Action( sf::Keyboard::I, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::JPRESS] = thor::Action( sf::Keyboard::J, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::KPRESS] = thor::Action( sf::Keyboard::K, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::LPRESS] = thor::Action( sf::Keyboard::L, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::MPRESS] = thor::Action( sf::Keyboard::M, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NPRESS] = thor::Action( sf::Keyboard::N, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::OPRESS] = thor::Action( sf::Keyboard::O, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::PPRESS] = thor::Action( sf::Keyboard::P, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::QPRESS] = thor::Action( sf::Keyboard::Q, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::RPRESS] = thor::Action( sf::Keyboard::R, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::SPRESS] = thor::Action( sf::Keyboard::S, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::TPRESS] = thor::Action( sf::Keyboard::T, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::UPRESS] = thor::Action( sf::Keyboard::U, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::VPRESS] = thor::Action( sf::Keyboard::V, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::WPRESS] = thor::Action( sf::Keyboard::W, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::XPRESS] = thor::Action( sf::Keyboard::X, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::YPRESS] = thor::Action( sf::Keyboard::Y, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::ZPRESS] = thor::Action( sf::Keyboard::Z, thor::Action::PressOnce ) ;

        //Numbers (press)
        _keyboardMap[KAI::NUM0PRESS] = thor::Action( sf::Keyboard::Num0, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUM1PRESS] = thor::Action( sf::Keyboard::Num1, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUM2PRESS] = thor::Action( sf::Keyboard::Num2, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUM3PRESS] = thor::Action( sf::Keyboard::Num3, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUM4PRESS] = thor::Action( sf::Keyboard::Num4, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUM5PRESS] = thor::Action( sf::Keyboard::Num5, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUM6PRESS] = thor::Action( sf::Keyboard::Num6, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUM7PRESS] = thor::Action( sf::Keyboard::Num7, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUM8PRESS] = thor::Action( sf::Keyboard::Num8, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUM9PRESS] = thor::Action( sf::Keyboard::Num9, thor::Action::PressOnce ) ;

        //Other function keys (press)
        _keyboardMap[KAI::ESCAPEPRESS] = thor::Action( sf::Keyboard::Escape, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::LCONTROLPRESS] = thor::Action( sf::Keyboard::LControl, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::LSHIFTPRESS] = thor::Action( sf::Keyboard::LShift, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::LALTPRESS] = thor::Action( sf::Keyboard::LAlt, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::LSYSTEMPRESS] = thor::Action( sf::Keyboard::LSystem, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::RCONTROLPRESS] = thor::Action( sf::Keyboard::RControl, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::RSHIFTPRESS] = thor::Action( sf::Keyboard::RShift, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::RSYSTEMPRESS] = thor::Action( sf::Keyboard::RSystem, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::MENUPRESS] = thor::Action( sf::Keyboard::Menu, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::LBRACKETPRESS] = thor::Action( sf::Keyboard::LBracket, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::RBRACKETPRESS] = thor::Action( sf::Keyboard::RBracket, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::SEMICOLONPRESS] = thor::Action( sf::Keyboard::SemiColon, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::COMMAPRESS] = thor::Action( sf::Keyboard::Comma, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::PERIODPRESS] = thor::Action( sf::Keyboard::Period, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::QUOTEPRESS] = thor::Action( sf::Keyboard::Quote, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::SLASHPRESS] = thor::Action( sf::Keyboard::Slash, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::BACKSLASHPRESS] = thor::Action( sf::Keyboard::BackSlash, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::TILDEPRESS] = thor::Action( sf::Keyboard::Tilde, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::EQUALPRESS] = thor::Action( sf::Keyboard::Equal, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::DASHPRESS] = thor::Action( sf::Keyboard::Dash, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::SPACEPRESS] = thor::Action( sf::Keyboard::Space, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::RETURNPRESS] = thor::Action( sf::Keyboard::Return, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::BACKSPACEPRESS] = thor::Action( sf::Keyboard::BackSpace, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::TABPRESS] = thor::Action( sf::Keyboard::Tab, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::PAGEUPPRESS] = thor::Action( sf::Keyboard::PageUp, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::PAGEDOWNPRESS] = thor::Action( sf::Keyboard::PageDown, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::ENDPRESS] = thor::Action( sf::Keyboard::End, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::HOMEPRESS] = thor::Action( sf::Keyboard::Home, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::INSERTPRESS] = thor::Action( sf::Keyboard::Insert, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::DELETEPRESS] = thor::Action( sf::Keyboard::Delete, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::ADDPRESS] = thor::Action( sf::Keyboard::Add, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::SUBTRACTPRESS] = thor::Action( sf::Keyboard::Subtract, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::MULTIPLYPRESS] = thor::Action( sf::Keyboard::Multiply, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::DIVIDEPRESS] = thor::Action( sf::Keyboard::Divide, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::LEFTPRESS] = thor::Action( sf::Keyboard::Left, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::RIGHTPRESS] = thor::Action( sf::Keyboard::Right, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::UPPRESS] = thor::Action( sf::Keyboard::Up, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::DOWNPRESS] = thor::Action( sf::Keyboard::Down, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::PAUSEPRESS] = thor::Action( sf::Keyboard::Pause, thor::Action::PressOnce ) ;

        //Numpad (press)
        _keyboardMap[KAI::NUMPAD0PRESS] = thor::Action( sf::Keyboard::Numpad0, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUMPAD1PRESS] = thor::Action( sf::Keyboard::Numpad1, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUMPAD2PRESS] = thor::Action( sf::Keyboard::Numpad2, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUMPAD3PRESS] = thor::Action( sf::Keyboard::Numpad3, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUMPAD4PRESS] = thor::Action( sf::Keyboard::Numpad4, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUMPAD5PRESS] = thor::Action( sf::Keyboard::Numpad5, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUMPAD6PRESS] = thor::Action( sf::Keyboard::Numpad6, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUMPAD7PRESS] = thor::Action( sf::Keyboard::Numpad7, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUMPAD8PRESS] = thor::Action( sf::Keyboard::Numpad8, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::NUMPAD9PRESS] = thor::Action( sf::Keyboard::Numpad9, thor::Action::PressOnce ) ;

        //Function keys (press)
        _keyboardMap[KAI::F1PRESS] = thor::Action( sf::Keyboard::F1, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F2PRESS] = thor::Action( sf::Keyboard::F2, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F3PRESS] = thor::Action( sf::Keyboard::F3, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F4PRESS] = thor::Action( sf::Keyboard::F4, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F5PRESS] = thor::Action( sf::Keyboard::F5, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F6PRESS] = thor::Action( sf::Keyboard::F6, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F7PRESS] = thor::Action( sf::Keyboard::F7, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F8PRESS] = thor::Action( sf::Keyboard::F8, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F9PRESS] = thor::Action( sf::Keyboard::F9, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F10PRESS] = thor::Action( sf::Keyboard::F10, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F11PRESS] = thor::Action( sf::Keyboard::F11, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F12PRESS] = thor::Action( sf::Keyboard::F12, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F13PRESS] = thor::Action( sf::Keyboard::F13, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F14PRESS] = thor::Action( sf::Keyboard::F14, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::F15PRESS] = thor::Action( sf::Keyboard::F15, thor::Action::PressOnce ) ;


        /*********************************************************************************************
        *****************************************HOLD************************************************/


        //Alphabet (hold)
        _keyboardMap[KAI::AHOLD] = thor::Action( sf::Keyboard::A, thor::Action::Hold ) ;
        _keyboardMap[KAI::BHOLD] = thor::Action( sf::Keyboard::B, thor::Action::Hold ) ;
        _keyboardMap[KAI::CHOLD] = thor::Action( sf::Keyboard::C, thor::Action::Hold ) ;
        _keyboardMap[KAI::DHOLD] = thor::Action( sf::Keyboard::D, thor::Action::Hold ) ;
        _keyboardMap[KAI::EHOLD] = thor::Action( sf::Keyboard::E, thor::Action::Hold ) ;
        _keyboardMap[KAI::FHOLD] = thor::Action( sf::Keyboard::F, thor::Action::Hold ) ;
        _keyboardMap[KAI::GHOLD] = thor::Action( sf::Keyboard::G, thor::Action::Hold ) ;
        _keyboardMap[KAI::HHOLD] = thor::Action( sf::Keyboard::H, thor::Action::Hold ) ;
        _keyboardMap[KAI::IHOLD] = thor::Action( sf::Keyboard::I, thor::Action::Hold ) ;
        _keyboardMap[KAI::JHOLD] = thor::Action( sf::Keyboard::J, thor::Action::Hold ) ;
        _keyboardMap[KAI::KHOLD] = thor::Action( sf::Keyboard::K, thor::Action::Hold ) ;
        _keyboardMap[KAI::LHOLD] = thor::Action( sf::Keyboard::L, thor::Action::Hold ) ;
        _keyboardMap[KAI::MHOLD] = thor::Action( sf::Keyboard::M, thor::Action::Hold ) ;
        _keyboardMap[KAI::NHOLD] = thor::Action( sf::Keyboard::N, thor::Action::Hold ) ;
        _keyboardMap[KAI::OHOLD] = thor::Action( sf::Keyboard::O, thor::Action::Hold ) ;
        _keyboardMap[KAI::PHOLD] = thor::Action( sf::Keyboard::P, thor::Action::Hold ) ;
        _keyboardMap[KAI::QHOLD] = thor::Action( sf::Keyboard::Q, thor::Action::Hold ) ;
        _keyboardMap[KAI::RHOLD] = thor::Action( sf::Keyboard::R, thor::Action::Hold ) ;
        _keyboardMap[KAI::SHOLD] = thor::Action( sf::Keyboard::S, thor::Action::Hold ) ;
        _keyboardMap[KAI::THOLD] = thor::Action( sf::Keyboard::T, thor::Action::Hold ) ;
        _keyboardMap[KAI::UHOLD] = thor::Action( sf::Keyboard::U, thor::Action::Hold ) ;
        _keyboardMap[KAI::VHOLD] = thor::Action( sf::Keyboard::V, thor::Action::Hold ) ;
        _keyboardMap[KAI::WHOLD] = thor::Action( sf::Keyboard::W, thor::Action::Hold ) ;
        _keyboardMap[KAI::XHOLD] = thor::Action( sf::Keyboard::X, thor::Action::Hold ) ;
        _keyboardMap[KAI::YHOLD] = thor::Action( sf::Keyboard::Y, thor::Action::Hold ) ;
        _keyboardMap[KAI::ZHOLD] = thor::Action( sf::Keyboard::Z, thor::Action::Hold ) ;

        //Numbers (hold)
        _keyboardMap[KAI::NUM0HOLD] = thor::Action( sf::Keyboard::Num0, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUM1HOLD] = thor::Action( sf::Keyboard::Num1, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUM2HOLD] = thor::Action( sf::Keyboard::Num2, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUM3HOLD] = thor::Action( sf::Keyboard::Num3, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUM4HOLD] = thor::Action( sf::Keyboard::Num4, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUM5HOLD] = thor::Action( sf::Keyboard::Num5, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUM6HOLD] = thor::Action( sf::Keyboard::Num6, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUM7HOLD] = thor::Action( sf::Keyboard::Num7, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUM8HOLD] = thor::Action( sf::Keyboard::Num8, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUM9HOLD] = thor::Action( sf::Keyboard::Num9, thor::Action::Hold ) ;

        //Other function keys (hold)
        _keyboardMap[KAI::ESCAPEHOLD] = thor::Action( sf::Keyboard::Escape, thor::Action::Hold ) ;
        _keyboardMap[KAI::LCONTROLHOLD] = thor::Action( sf::Keyboard::LControl, thor::Action::Hold ) ;
        _keyboardMap[KAI::LSHIFTHOLD] = thor::Action( sf::Keyboard::LShift, thor::Action::Hold ) ;
        _keyboardMap[KAI::LALTHOLD] = thor::Action( sf::Keyboard::LAlt, thor::Action::Hold ) ;
        _keyboardMap[KAI::LSYSTEMHOLD] = thor::Action( sf::Keyboard::LSystem, thor::Action::Hold ) ;
        _keyboardMap[KAI::RCONTROLHOLD] = thor::Action( sf::Keyboard::RControl, thor::Action::Hold ) ;
        _keyboardMap[KAI::RSHIFTHOLD] = thor::Action( sf::Keyboard::RShift, thor::Action::Hold ) ;
        _keyboardMap[KAI::RSYSTEMHOLD] = thor::Action( sf::Keyboard::RSystem, thor::Action::Hold ) ;
        _keyboardMap[KAI::MENUHOLD] = thor::Action( sf::Keyboard::Menu, thor::Action::Hold ) ;
        _keyboardMap[KAI::LBRACKETHOLD] = thor::Action( sf::Keyboard::LBracket, thor::Action::Hold ) ;
        _keyboardMap[KAI::RBRACKETHOLD] = thor::Action( sf::Keyboard::RBracket, thor::Action::Hold ) ;
        _keyboardMap[KAI::SEMICOLONHOLD] = thor::Action( sf::Keyboard::SemiColon, thor::Action::Hold ) ;
        _keyboardMap[KAI::COMMAHOLD] = thor::Action( sf::Keyboard::Comma, thor::Action::Hold ) ;
        _keyboardMap[KAI::PERIODHOLD] = thor::Action( sf::Keyboard::Period, thor::Action::Hold ) ;
        _keyboardMap[KAI::QUOTEHOLD] = thor::Action( sf::Keyboard::Quote, thor::Action::Hold ) ;
        _keyboardMap[KAI::SLASHHOLD] = thor::Action( sf::Keyboard::Slash, thor::Action::Hold ) ;
        _keyboardMap[KAI::BACKSLASHHOLD] = thor::Action( sf::Keyboard::BackSlash, thor::Action::Hold ) ;
        _keyboardMap[KAI::TILDEHOLD] = thor::Action( sf::Keyboard::Tilde, thor::Action::Hold ) ;
        _keyboardMap[KAI::EQUALHOLD] = thor::Action( sf::Keyboard::Equal, thor::Action::Hold ) ;
        _keyboardMap[KAI::DASHHOLD] = thor::Action( sf::Keyboard::Dash, thor::Action::Hold ) ;
        _keyboardMap[KAI::SPACEHOLD] = thor::Action( sf::Keyboard::Space, thor::Action::Hold ) ;
        _keyboardMap[KAI::RETURNHOLD] = thor::Action( sf::Keyboard::Return, thor::Action::Hold ) ;
        _keyboardMap[KAI::BACKSPACEHOLD] = thor::Action( sf::Keyboard::BackSpace, thor::Action::Hold ) ;
        _keyboardMap[KAI::TABHOLD] = thor::Action( sf::Keyboard::Tab, thor::Action::Hold ) ;
        _keyboardMap[KAI::PAGEUPHOLD] = thor::Action( sf::Keyboard::PageUp, thor::Action::Hold ) ;
        _keyboardMap[KAI::PAGEDOWNHOLD] = thor::Action( sf::Keyboard::PageDown, thor::Action::Hold ) ;
        _keyboardMap[KAI::ENDHOLD] = thor::Action( sf::Keyboard::End, thor::Action::Hold ) ;
        _keyboardMap[KAI::HOMEHOLD] = thor::Action( sf::Keyboard::Home, thor::Action::Hold ) ;
        _keyboardMap[KAI::INSERTHOLD] = thor::Action( sf::Keyboard::Insert, thor::Action::Hold ) ;
        _keyboardMap[KAI::DELETEHOLD] = thor::Action( sf::Keyboard::Delete, thor::Action::Hold ) ;
        _keyboardMap[KAI::ADDHOLD] = thor::Action( sf::Keyboard::Add, thor::Action::Hold ) ;
        _keyboardMap[KAI::SUBTRACTHOLD] = thor::Action( sf::Keyboard::Subtract, thor::Action::Hold ) ;
        _keyboardMap[KAI::MULTIPLYHOLD] = thor::Action( sf::Keyboard::Multiply, thor::Action::Hold ) ;
        _keyboardMap[KAI::DIVIDEHOLD] = thor::Action( sf::Keyboard::Divide, thor::Action::Hold ) ;
        _keyboardMap[KAI::LEFTHOLD] = thor::Action( sf::Keyboard::Left, thor::Action::Hold ) ;
        _keyboardMap[KAI::RIGHTHOLD] = thor::Action( sf::Keyboard::Right, thor::Action::Hold ) ;
        _keyboardMap[KAI::UPHOLD] = thor::Action( sf::Keyboard::Up, thor::Action::Hold ) ;
        _keyboardMap[KAI::DOWNHOLD] = thor::Action( sf::Keyboard::Down, thor::Action::Hold ) ;
        _keyboardMap[KAI::PAUSEHOLD] = thor::Action( sf::Keyboard::Pause, thor::Action::Hold ) ;

        //Numpad (hold)
        _keyboardMap[KAI::NUMPAD0HOLD] = thor::Action( sf::Keyboard::Numpad0, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUMPAD1HOLD] = thor::Action( sf::Keyboard::Numpad1, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUMPAD2HOLD] = thor::Action( sf::Keyboard::Numpad2, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUMPAD3HOLD] = thor::Action( sf::Keyboard::Numpad3, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUMPAD4HOLD] = thor::Action( sf::Keyboard::Numpad4, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUMPAD5HOLD] = thor::Action( sf::Keyboard::Numpad5, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUMPAD6HOLD] = thor::Action( sf::Keyboard::Numpad6, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUMPAD7HOLD] = thor::Action( sf::Keyboard::Numpad7, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUMPAD8HOLD] = thor::Action( sf::Keyboard::Numpad8, thor::Action::Hold ) ;
        _keyboardMap[KAI::NUMPAD9HOLD] = thor::Action( sf::Keyboard::Numpad9, thor::Action::Hold ) ;

        //Function keys (hold)
        _keyboardMap[KAI::F1HOLD] = thor::Action( sf::Keyboard::F1, thor::Action::Hold ) ;
        _keyboardMap[KAI::F2HOLD] = thor::Action( sf::Keyboard::F2, thor::Action::Hold ) ;
        _keyboardMap[KAI::F3HOLD] = thor::Action( sf::Keyboard::F3, thor::Action::Hold ) ;
        _keyboardMap[KAI::F4HOLD] = thor::Action( sf::Keyboard::F4, thor::Action::Hold ) ;
        _keyboardMap[KAI::F5HOLD] = thor::Action( sf::Keyboard::F5, thor::Action::Hold ) ;
        _keyboardMap[KAI::F6HOLD] = thor::Action( sf::Keyboard::F6, thor::Action::Hold ) ;
        _keyboardMap[KAI::F7HOLD] = thor::Action( sf::Keyboard::F7, thor::Action::Hold ) ;
        _keyboardMap[KAI::F8HOLD] = thor::Action( sf::Keyboard::F8, thor::Action::Hold ) ;
        _keyboardMap[KAI::F9HOLD] = thor::Action( sf::Keyboard::F9, thor::Action::Hold ) ;
        _keyboardMap[KAI::F10HOLD] = thor::Action( sf::Keyboard::F10, thor::Action::Hold ) ;
        _keyboardMap[KAI::F11HOLD] = thor::Action( sf::Keyboard::F11, thor::Action::Hold ) ;
        _keyboardMap[KAI::F12HOLD] = thor::Action( sf::Keyboard::F12, thor::Action::Hold ) ;
        _keyboardMap[KAI::F13HOLD] = thor::Action( sf::Keyboard::F13, thor::Action::Hold ) ;
        _keyboardMap[KAI::F14HOLD] = thor::Action( sf::Keyboard::F14, thor::Action::Hold ) ;
        _keyboardMap[KAI::F15HOLD] = thor::Action( sf::Keyboard::F15, thor::Action::Hold ) ;

        //Mouse user input
        _keyboardMap[KAI::LEFTMOUSEPRESSED] = thor::Action( sf::Mouse::Left, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::LEFTMOUSEHOLD] = thor::Action( sf::Mouse::Left, thor::Action::Hold ) ;
        _keyboardMap[KAI::RIGHTMOUSEPRESSED] = thor::Action( sf::Mouse::Right, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::RIGHTMOUSEHOLD] = thor::Action( sf::Mouse::Right, thor::Action::Hold ) ;
        _keyboardMap[KAI::MIDDLEPRESS] = thor::Action( sf::Mouse::Middle, thor::Action::PressOnce ) ;
        _keyboardMap[KAI::MIDDLEHOLD] = thor::Action( sf::Mouse::Middle, thor::Action::Hold ) ;

        //sf::Event user input
        _keyboardMap[KAI::CLOSED] = thor::Action( sf::Event::Closed ) ;
        _keyboardMap[KAI::TEXTENTERED] = thor::Action( sf::Event::TextEntered ) ;
        _keyboardMap[KAI::MOUSELEFT] = thor::Action( sf::Event::MouseLeft ) ;
        _keyboardMap[KAI::MOUSEENTERED] = thor::Action( sf::Event::MouseEntered ) ;
    }
}}