//
// Created by Peter Senyszyn on 7/21/18.
//

#ifndef SHOCKENGINE_APPLICATION_HPP
#define SHOCKENGINE_APPLICATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>

namespace Shock
{
namespace Core
{
    class Application
    {
    private:
        sf::RenderWindow _renderWindow ;

        float _maxFps ;

    public:
        Application() ;

        void processInput() ;
        void update( sf::Time dt ) ;
        void render() ;

        const bool isRunning() const ;
        const void quit() ;

        const float getMaxFps() const ;
        const float setMaxFps( const float value ) ;
    } ;
}}

#endif //SHOCKENGINE_APPLICATION_HPP
