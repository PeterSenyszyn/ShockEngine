//
// Created by Peter Senyszyn on 7/24/18.
//

#include "../../include/Core/ContextBuffer.hpp"

namespace Shock
{
namespace Core
{
    ContextBuffer::ContextBuffer( sf::RenderWindow& window,
                                  Core::StateStack& stateStack,
                                  Input::InputManager& inputManager,
                                  Render::RenderedObjectManager& renderedObjectManager,
                                  TextureHolder& textureHolder,
                                  FontHolder& fontHolder ) :
    window( &window ),
    stateStack( &stateStack ),
    inputManager( &inputManager ),
    renderedObjectManager( &renderedObjectManager ),
    textureHolder( &textureHolder ),
    fontHolder( &fontHolder )
    {
    }
}}