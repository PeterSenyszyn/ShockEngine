//
// Created by Peter Senyszyn on 7/21/18.
//

#ifndef SHOCKENGINE_MANAGER_HPP
#define SHOCKENGINE_MANAGER_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace Shock
{
namespace Core
{
    class InputManager ;

    class Manager
    {
    public:
        Manager() = default ;
        virtual ~Manager() = default ;

        virtual void update( sf::Time dt ) {}
        virtual void render( sf::RenderTarget& target, sf::RenderStates states ) const {}
    } ;
}}

#endif //SHOCKENGINE_MANAGER_HPP
