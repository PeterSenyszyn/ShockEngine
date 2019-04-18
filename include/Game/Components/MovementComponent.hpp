//
// Created by petersenyszyn on 4/12/19.
//

#ifndef SHOCKENGINE_MOVEMENTCOMPONENT_HPP
#define SHOCKENGINE_MOVEMENTCOMPONENT_HPP

#include <tuple>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "Component.hpp"

namespace Shock::Game
{
    using namespace Shock::Input ; //To simplify key declarations

    //Component for player movement
    class MovementComponent : public Component
    {
    public:
        MovementComponent( sf::Vector2f       speedVector  = sf::Vector2f(),
                           sf::Transformable* objectToMove = nullptr ) ;

        ~MovementComponent() override = default ;

        void handleEvent( Input::InputManager& inputManager ) override ;
        void update( sf::Time dt ) override ;

        void setHotKeys( KAI upKey, KAI leftKey, KAI downKey, KAI rightKey ) ;

    private:
        sf::Vector2f _speedVector ; //Speed in 2D (base speed)
        sf::Vector2f _velocityVector ;

        sf::Transformable* _objectToMove ;

        //Keycodes for different directions
        //4 cardinal directions
        KAI  _upKey ;                               //vector ( xDelta = 0, yDelta < 0 )
        KAI  _leftKey ;                             //vector ( xDelta < 0, yDelta = 0 )
        KAI  _downKey ;                             //vector ( xDelta = 0, yDelta > 0 )
        KAI  _rightKey ;                            //vector ( xDelta > 0, yDelta = 0 )
    } ;
}

#endif //SHOCKENGINE_MOVEMENTCOMPONENT_HPP