//
// Created by Peter Senyszyn on 7/21/18.
//

#ifndef SHOCKENGINE_MANAGER_HPP
#define SHOCKENGINE_MANAGER_HPP

#include <SFML/System/Time.hpp>

namespace Shock
{
namespace Core
{
    class Manager
    {
    private:

    public:
        Manager() = default ;

        virtual ~Manager() = default ;

        virtual void processInput() {}
        virtual void update( sf::Time dt ) {}
        virtual void render() {}
    } ;
}}

#endif //SHOCKENGINE_MANAGER_HPP
