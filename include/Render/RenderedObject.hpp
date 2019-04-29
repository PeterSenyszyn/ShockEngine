//
// Created by Peter Senyszyn on 7/24/18.
//

#ifndef SHOCKENGINE_RENDEREDOBJECT_HPP
#define SHOCKENGINE_RENDEREDOBJECT_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "../Input/InputManager.hpp"

namespace Shock::Render
{
    class RenderedObject : public sf::Drawable, public sf::Transformable
    {
    private:
        bool _enabled ;

    protected:
        void draw( sf::RenderTarget& target, sf::RenderStates states ) const override ;

    public:
        explicit RenderedObject() ;
        ~RenderedObject() override = default ;

        virtual void applyCustomTransforms( sf::RenderStates states ) const ;
        virtual void handleEvent( Input::InputManager& inputManager ) = 0 ;
        virtual void update( sf::Time dt ) = 0 ;
        virtual void render( sf::RenderTarget& target, sf::RenderStates states ) const = 0 ;

        const bool isEnabled() const ;
        const void setEnabled( bool value ) ;
    } ;
}

#endif //SHOCKENGINE_RENDEREDOBJECT_HPP