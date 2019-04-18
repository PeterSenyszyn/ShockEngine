//
// Created by petersenyszyn on 4/12/19.
//

#ifndef SHOCKENGINE_MOVEMENTCOMPONENT_HPP
#define SHOCKENGINE_MOVEMENTCOMPONENT_HPP

#include <SFML/System/Vector2.hpp>

#include "Component.hpp"

namespace Shock
{
namespace Game
{
    //Component for
    class MovementComponent : public Component
    {
    public:
        MovementComponent( sf::Vector2f speedVector = sf::Vector2f() ) ;
        ~MovementComponent() override = default ;

        void handleEvent( Input::InputManager& inputManager ) override;
        void update( sf::Time dt ) override;

    private:
        sf::Vector2f _speedVector ;
    } ;
}}

#endif //SHOCKENGINE_MOVEMENTCOMPONENT_HPP