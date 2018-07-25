//
// Created by Peter Senyszyn on 7/24/18.
//

#ifndef SHOCKENGINE_CONTEXTBUFFER_HPP
#define SHOCKENGINE_CONTEXTBUFFER_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

#include "../Input/InputManager.hpp"
#include "../Resource/ResourceHolder.hpp"
#include "../Resource/ResourceIdentifiers.hpp"

namespace Shock
{
namespace Core
{
    //Holds all pointers to various managers and other
    //necessary objects for the states
    struct ContextBuffer
    {
        typedef Resource::ResourceHolder<sf::Texture, Resource::Textures> TextureHolder ;
        typedef Resource::ResourceHolder<sf::Font, Resource::Fonts> FontHolder ;

        ContextBuffer( sf::RenderWindow& window,
                       Input::InputManager& inputManager,
                       TextureHolder& textureHolder,
                       FontHolder& fontHolder ) ;

        //SFML
        sf::RenderWindow* window ;

        //Managers
        Input::InputManager* inputManager ;

        //Resources
        TextureHolder* textureHolder ;
        FontHolder*       fontHolder ;
    } ;
}}


#endif //SHOCKENGINE_CONTEXTBUFFER_HPP
