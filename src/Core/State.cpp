//
// Created by Peter Senyszyn on 7/22/18.
//

#include "../../include/Core/State.hpp"
#include "../../include/Core/StateStack.hpp"

namespace Shock
{
namespace Core
{
    ////////////////////////////////////////////////////////////////////////////////////////

    State::Context::Context( ContextBuffer& buffer ) :
    buffer( &buffer )
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////

    void State::requestStackPush( StateIds stateId )
    {
        _stack->pushState( stateId ) ;
    }

    void State::requestStackPop()
    {
        _stack->popState() ;
    }

    void State::requestStateClear()
    {
        _stack->clearStates() ;
    }

    State::Context State::getContext() const
    {
        return _context ;
    }

    const std::string& State::getStateName()
    {
        return typeid( this ).name() ;
    }

    ////////////////////////////////////////////////////////////////////////////////////////

    State::State( StateStack& stack, Context context ) :
    _stack( &stack ),
    _context( context )
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////
}}