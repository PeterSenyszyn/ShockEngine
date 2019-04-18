//
// Created by Peter Senyszyn on 7/24/18.
//

#ifndef SHOCKENGINE_GAMESTATE_HPP
#define SHOCKENGINE_GAMESTATE_HPP

#include <SFML/Graphics/CircleShape.hpp>

#include "../Core/State.hpp"
#include "../Game/World.hpp"

namespace Shock
{
namespace States
{
    class GameState : public Core::State
    {
    private:
        Game::World _world ;

    public:
        GameState( Core::StateStack& stack, Context context ) ;

        bool handleEvent( const sf::Event& event ) override ;
        bool update( sf::Time dt ) override ;
        void draw() override ;
    } ;
}}

#endif //SHOCKENGINE_GAMESTATE_HPP