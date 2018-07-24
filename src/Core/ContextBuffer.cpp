//
// Created by Peter Senyszyn on 7/24/18.
//

#include "../../include/Core/ContextBuffer.hpp"

namespace Shock
{
namespace Core
{
    ContextBuffer::ContextBuffer( sf::RenderWindow &window,
                                  Input::InputManager& inputManager ) :
    window( &window ),
    inputManager( &inputManager )
    {
    }
}}