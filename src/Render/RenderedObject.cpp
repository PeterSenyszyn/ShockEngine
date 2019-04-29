//
// Created by Peter Senyszyn on 7/24/18.
//

#include "../../include/Render/RenderedObject.hpp"

namespace Shock::Render
{
    RenderedObject::RenderedObject() :
    _enabled( true )
    {

    }

    //Basic transform applied by default, but method is virtual so
    //can be modified on a per-object basis
    void RenderedObject::applyCustomTransforms( sf::RenderStates states ) const
    {
        states.transform *= this->getTransform() ;
    }

    void RenderedObject::draw( sf::RenderTarget& target, sf::RenderStates states ) const
    {
        this->applyCustomTransforms( states ) ;
        this->render( target, states ) ;
    }

    ////////////////////////////////////////////////////////////////////////

    const bool RenderedObject::isEnabled() const
    { return _enabled ; }

    const void RenderedObject::setEnabled( bool value )
    {  _enabled = value ; }
}