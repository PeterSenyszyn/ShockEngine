//
// Created by Peter Senyszyn on 7/24/18.
//

#ifndef SHOCKENGINE_CONTEXTBUFFER_HPP
#define SHOCKENGINE_CONTEXTBUFFER_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include "../Input/InputManager.hpp"

namespace Shock
{
namespace Core
{
    //Holds all pointers to various managers and other
    //necessary objects for the states
    struct ContextBuffer
    {
        ContextBuffer( sf::RenderWindow& window,
                       Input::InputManager& inputManager ) ;

        //SFML
        sf::RenderWindow* window ;

        //Managers
        Input::InputManager* inputManager ;
    } ;
}}


#endif //SHOCKENGINE_CONTEXTBUFFER_HPP
