//
// Created by petersenyszyn on 4/12/19.
//

#ifndef SHOCKENGINE_COMPONENT_HPP
#define SHOCKENGINE_COMPONENT_HPP

#include <string>

namespace Shock
{
namespace Game
{
    //Interface
    class Component
    {
    public:
        Component( const std::string& name ) ;

        virtual ~Component() = default ;

        const void setName( const std::string& name ) ;
        const std::string& getName() const ;

    private:
        std::string _name ;
    } ;
}}

#endif //SHOCKENGINE_COMPONENT_HPP