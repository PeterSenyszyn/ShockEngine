//
// Created by petersenyszyn on 4/6/19.
//

#ifndef SHOCKENGINE_STRINGUTILS_HPP
#define SHOCKENGINE_STRINGUTILS_HPP

#include <string>

namespace Shock
{
namespace Utils
{
    //Check if string has certain file ending (mostly for file extension checking)
    bool hasEnding( const std::string& fullString, const std::string& ending )
    {
        auto fullLen = fullString.length() ;
        auto endLen  = ending.length() ;

        if ( fullLen >= endLen )
            return ( 0 == fullString.compare( fullLen - endLen, endLen, ending ) ) ;

        return false ;
    }
}}

#endif //SHOCKENGINE_STRINGUTILS_HPP
