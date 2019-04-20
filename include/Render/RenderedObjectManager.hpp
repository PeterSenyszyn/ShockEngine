//
// Created by Peter Senyszyn on 7/24/18.
//

#ifndef SHOCKENGINE_RENDEREDOBJECTMANAGER_HPP
#define SHOCKENGINE_RENDEREDOBJECTMANAGER_HPP

#include <map>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#include "RenderedObject.hpp"
#include "../Core/Manager.hpp"

namespace Shock::Render
{
    class RenderedObjectManager : public Core::Manager
    {
    private:
        std::map<std::string, std::unique_ptr<RenderedObject> > _objects ;

    public:
        void addRenderedObject( const std::string& id,
                                std::unique_ptr<RenderedObject> object ) ;

        RenderedObject& getRenderedObject( const std::string& id ) ;
        const RenderedObject& getRenderedObject( const std::string& id ) const ;

        void handleEvent( Input::InputManager& inputManager ) ;

        void update( sf::Time dt ) override ;
        void render( sf::RenderTarget& target, sf::RenderStates states ) const override ;

        unsigned long getNumRenderedObjects() const ;
    } ;
}

#endif //SHOCKENGINE_RENDEREDOBJECTMANAGER_HPP