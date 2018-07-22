#include <iostream>

#include "include/Core/Application.hpp"

int main()
{
    Shock::Core::Application app ;

    try
    {
        sf::Clock deltaClock ;

        sf::Time lastUpdate = sf::Time::Zero ;

        while ( app.isRunning() )
        {
            sf::Time timePerFrame = sf::seconds( 1.f / app.getMaxFps() ) ;

            lastUpdate += deltaClock.restart() ;

            while ( lastUpdate > timePerFrame )
            {
                lastUpdate -= timePerFrame ;

                app.processInput() ;
                app.update( timePerFrame ) ;
                app.render() ;
            }
        }
    }

    catch( std::exception& e )
    {
        std::cout << "Exception when running application: " << e.what() << std::endl ;
    }

    return 0 ;
}