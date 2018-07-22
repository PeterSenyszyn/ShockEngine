//
// Created by Peter Senyszyn on 7/22/18.
//

#ifndef SHOCKENGINE_STATE_HPP
#define SHOCKENGINE_STATE_HPP

#include <memory>

#include <SFML/Window/Event.hpp>

#include "StateIds.hpp"

namespace Shock
{
namespace Core
{
    class StateStack ;

    class State
    {
    public:
        typedef std::unique_ptr<State> Ptr ;

        struct Context
        {
            Context() ;
        } ;

    private:
        StateStack* _stack ;
        Context     _context ;

    protected:
        void requestStackPush( StateIds stateId ) ;
        void requestStackPop() ;
        void requestStateClear() ;

        Context getContext() const ;

    public:
        State( StateStack& stack, Context context ) ;
        virtual ~State() = default ;

        virtual bool handleEvent( const sf::Event& event ) = 0;
        virtual bool update( sf::Time dt ) = 0 ;
        virtual void draw() = 0 ;
    } ;
}}

#endif //SHOCKENGINE_STATE_HPP