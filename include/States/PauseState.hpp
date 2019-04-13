//
// Created by Peter Senyszyn on 7/24/18.
//

#ifndef SHOCKENGINE_PAUSESTATE_HPP
#define SHOCKENGINE_PAUSESTATE_HPP

#include "../Core/State.hpp"

namespace Shock
{
namespace States
{
    class PauseState : public Core::State
    {
    public:
        bool handleEvent( const sf::Event& event ) override ;
        bool update( sf::Time dt ) override ;
        void draw() override ;
    } ;
}}


#endif //SHOCKENGINE_PAUSESTATE_HPP
