//
// Created by Peter Senyszyn on 7/22/18.
//

#include "../../include/Core/StateStack.hpp"

namespace Shock
{
namespace Core
{
    ///////////////////////////////////////////////////////////////////////
    //PendingChange
    ///////////////////////////////////////////////////////////////////////

    StateStack::PendingChange::PendingChange( Action action, StateIds stateId ) :
    action( action ),
    stateId( stateId )
    {
    }

    ///////////////////////////////////////////////////////////////////////

    State::Ptr StateStack::createState( StateIds stateId )
    {
        auto found = _factories.find( stateId ) ;

        assert( found != _factories.end() ) ;

        return found->second() ;
    }

    void StateStack::applyPendingChanges()
    {
        for ( const auto& change : _pendingList )
        {
            switch ( change.action )
            {
                case Action::Push:
                {
                    _stack.push_back( createState( change.stateId ) ) ;

                    break ;
                }

                case Action::Pop:
                {
                    _stack.pop_back() ;

                    break ;
                }

                case Action::Clear:
                {
                    _stack.clear() ;

                    break ;
                }
            }
        }

        _pendingList.clear() ;
    }

    ///////////////////////////////////////////////////////////////////////

    StateStack::StateStack( State::Context context ) :
    _context( context )
    {
    }

    void StateStack::handleEvent( const sf::Event& event )
    {
        //Iterate from top to bottom
        for ( auto iter = _stack.rbegin() ; iter != _stack.rend() ; iter++ )
        {
            //Stop if handleEvent() returns false
            if ( !( *iter )->handleEvent( event ) )
            {
                break ;
            }
        }

        applyPendingChanges() ;
    }

    void StateStack::update( sf::Time dt )
    {
        //Iterate from top to bottom
        for ( auto iter = _stack.rbegin() ; iter != _stack.rend() ; iter++ )
        {
            //Stop if update() returns false
            if ( !( *iter )->update( dt ) )
            {
                break ;
            }
        }

        applyPendingChanges() ;
    }

    void StateStack::draw()
    {
        for ( const auto& state : _stack )
        {
            state->draw() ;
        }
    }

    void StateStack::pushState( StateIds stateId )
    {
        _pendingList.push_back( PendingChange( Action::Push, stateId ) ) ;
    }

    void StateStack::popState()
    {
        _pendingList.push_back( PendingChange( Action::Pop ) ) ;
    }

    void StateStack::clearStates()
    {
        _pendingList.push_back( PendingChange( Action::Clear ) ) ;
    }

    bool StateStack::isEmpty() const
    {
        return _stack.empty() ;
    }

    ///////////////////////////////////////////////////////////////////////
}}