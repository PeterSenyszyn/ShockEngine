//
// Created by Peter Senyszyn on 7/22/18.
//

#ifndef SHOCKENGINE_STATESTACK_HPP
#define SHOCKENGINE_STATESTACK_HPP

#include <vector>
#include <map>

#include <SFML/System/NonCopyable.hpp>

#include "State.hpp"
#include "StateIds.hpp"

namespace Shock
{
namespace Core
{
    class StateStack : private sf::NonCopyable
    {
    public:
        enum class Action
        {
            Push,
            Pop,
            Clear
        } ;

    private:
        struct PendingChange
        {
            explicit PendingChange( Action action,
                                    StateIds stateId = StateIds::None ) ;

            StateStack::Action action ;
            StateIds           stateId ;
        } ;

    private:
        std::vector<State::Ptr>                             _stack ;
        std::vector<StateStack::PendingChange>              _pendingList ;
        State::Context                                      _context ;
        std::map<StateIds, std::function<State::Ptr()> >    _factories ;

    private:
        State::Ptr createState( StateIds stateId ) ;
        void applyPendingChanges() ;

    public:
        explicit StateStack( State::Context context ) ;

        template <typename T>
        void registerState( StateIds stateId ) ;

        void handleEvent( const sf::Event& event ) ;
        void update( sf::Time dt ) ;
        void draw() ;

        void pushState( StateIds stateId ) ;
        void popState() ;
        void clearStates() ;

        bool isEmpty() const ;
    } ;

    template <typename T>
    void StateStack::registerState( StateIds stateId )
    {
        _factories[stateId] = [this]()
        {
            return State::Ptr( new T( *this, _context ) ) ;
        } ;
    }
}}

#endif //SHOCKENGINE_STATESTACK_HPP