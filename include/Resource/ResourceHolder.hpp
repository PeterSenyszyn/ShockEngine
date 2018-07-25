//
// Created by Peter Senyszyn on 7/24/18.
//

#ifndef SHOCKENGINE_RESOURCEHOLDER_HPP
#define SHOCKENGINE_RESOURCEHOLDER_HPP

#include <string>
#include <map>

namespace Shock
{
namespace Resource
{
    template <class Resource, typename Identifier>
    class ResourceHolder
    {
    private:
        std::map<Identifier, std::unique_ptr<Resource> > _resourceMap ;

    private:
        void insertResource( Identifier id, std::unique_ptr<Resource> resource ) ;

    public:
        ResourceHolder() = default ;

        void load( Identifier id, const std::string& filepath ) ;

        template <typename Parameter>
        void load( Identifier id, const std::string& filepath, const Parameter& secondParam ) ;

        Resource& get( Identifier id ) ;
        const Resource& get( Identifier id ) const ;
    } ;

    //So the linker can find the implementations
    ////////////////////////////////////////////////////////////////////////////

    template <class Resource, typename Identifier>
    void ResourceHolder<Resource, Identifier>::insertResource( Identifier id, std::unique_ptr<Resource> resource )
    {
        //Insert and check success
        auto inserted = _resourceMap.insert( std::make_pair( id, std::move( resource ) ) ) ;

        assert( inserted.second ) ;
    }

    template <class Resource, typename Identifier>
    void ResourceHolder<Resource, Identifier>::load( Identifier id, const std::string& filepath )
    {
        //Create and load resource
        std::unique_ptr<Resource> resource( new Resource() ) ;

        if ( !resource->loadFromFile( filepath ) )
        {
            throw std::runtime_error( "ResourceHolder::load - Failed to load " + filepath ) ;
        }

        insertResource( id, std::move( resource ) ) ;
    }

    template <class Resource, typename Identifier>
    template <typename Parameter>
    void ResourceHolder<Resource, Identifier>::load( Identifier id, const std::string& filepath, const Parameter& secondParam )
    {
        //Create and load resource
        std::unique_ptr<Resource> resource( new Resource() ) ;

        if ( !resource->loadFromFile( filepath, secondParam ) )
        {
            throw std::runtime_error( "ResourceHolder::load - Failed to load " + filepath ) ;
        }

        insertResource( id, std::move( resource ) ) ;
    }

    template <class Resource, typename Identifier>
    Resource& ResourceHolder<Resource, Identifier>::get( Identifier id )
    {
        auto found = _resourceMap.find( id ) ;

        assert( found != _resourceMap.end() ) ;

        return *found->second ;
    }

    template <class Resource, typename Identifier>
    const Resource& ResourceHolder<Resource, Identifier>::get( Identifier id ) const
    {
        auto found = _resourceMap.find( id ) ;

        assert( found != _resourceMap.end() ) ;

        return *found->second ;
    }

    ////////////////////////////////////////////////////////////////////////////
}}

#endif //SHOCKENGINE_RESOURCEHOLDER_HPP