//
// Created by petersenyszyn on 4/6/19.
//

#ifndef SHOCKENGINE_MATRIX_HPP
#define SHOCKENGINE_MATRIX_HPP

#include <vector>
#include <stdexcept>

namespace Shock
{
namespace MathUtils
{
    template <class T>
    class Matrix2D
    {
    public:
        explicit Matrix2D( unsigned int width = 0, unsigned int height = 0 ) :
            _width( width ), _height( height )
        {
            _data.resize( width * height ) ;
        }

        T& get( unsigned int x, unsigned int y )
        {
            if ( x >= _width || y >= _height )
                throw std::out_of_range( "OOB exception in Matrix2D::get" ) ;

            return _data[_width * y + x] ;
        }

        T& operator()( unsigned int x, unsigned int y )
        {
            return get( x, y ) ;
        }

    private:
        std::vector<T> _data ;

        unsigned int _width ;
        unsigned int _height ;
    } ;

    //TODO
    template <class T>
    class Matrix3D
    {

    } ;
}}

#endif //SHOCKENGINE_MATRIX_HPP