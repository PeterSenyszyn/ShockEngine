//
// Created by Peter Senyszyn on 7/24/18.
//

#include "../../include/Core/ContextBuffer.hpp"

namespace Shock
{
namespace Core
{
    ContextBuffer::ContextBuffer( sf::RenderWindow& window,
                                  Input::InputManager& inputManager,
                                  TextureHolder& textureHolder,
                                  FontHolder& fontHolder ) :
    window( &window ),
    inputManager( &inputManager ),
    textureHolder( &textureHolder ),
    fontHolder( &fontHolder )
    {
    }
}}