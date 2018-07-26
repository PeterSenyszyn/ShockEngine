//
// Created by Peter Senyszyn on 7/24/18.
//

#ifndef SHOCKENGINE_RENDEREDOBJECTMANAGER_HPP
#define SHOCKENGINE_RENDEREDOBJECTMANAGER_HPP

#include <map>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#include "RenderedObject.hpp"

namespace Shock
{
namespace Render
{
    class RenderedObjectManager
    {
    private:
        std::map<std::string, std::unique_ptr<RenderedObject> > _objects ;

    public:
        void addRenderedObject( const std::string& id,
                                std::unique_ptr<RenderedObject> object ) ;

        RenderedObject& getRenderedObject( const std::string& id ) ;
        const RenderedObject& getRenderedObject( const std::string& id ) const ;

        void handleEvent( Input::InputManager& inputManager ) ;
        void update( sf::Time dt ) ;
        void draw( sf::RenderWindow& window ) ;

        unsigned long getNumRenderedObjects() const ;
    } ;
}}

#endif //SHOCKENGINE_RENDEREDOBJECTMANAGER_HPP