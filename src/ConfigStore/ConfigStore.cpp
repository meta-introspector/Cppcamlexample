// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include <ConfigStore.hpp>

#include <cstdlib>
#include <cstdio>

using namespace Engine;

ConfigValue::ConfigValue()
{
    type = CONFIG_NULL_VALUE;
    integer = 0;
}

ConfigValue::ConfigValue( int64_t num )
{
    type = CONFIG_INTEGER;
    integer = num;
}

ConfigValue::ConfigValue( std::string str )
{
    type = CONFIG_STRING;
    string = new std::string( str );
}

ConfigValue::~ConfigValue()
{
    switch( type ) {
        case CONFIG_NULL_VALUE:
            // do nothing
            break;
        case CONFIG_INTEGER:
            // do nothing
            break;
        case CONFIG_STRING:
            delete string;
            break;
    }
}

static void quitConfigStore()
{
    delete &( ConfigStore::instance() );
}

ConfigStore::ConfigStore()
{
    puts( "Initializing Configuration Store..." );
    defaultConfig();
    // TODO: load config from file here
}

ConfigStore& ConfigStore::instance()
{
    static ConfigStore* c;
    if ( c ) {
        return *c;
    } else {
        c = new ConfigStore();
        atexit( quitConfigStore );
        return *c;
    }
}

ConfigStore::~ConfigStore()
{
    puts( "Shutting down Configuration Store..." );
    // TODO
}

void ConfigStore::defaultConfig()
{
    // TODO: clear
    kvmap.clear();
    defaultConfigAdd();
}

void ConfigStore::defaultConfigAdd()
{
    // Renderer defaults
    // TODO: make a central place where all of these options and their defaults are registered to, preferably exported as "extern" at least inside of this library
    // @{
    kvmap.emplace( "r_width", 640 );
    kvmap.emplace( "r_height", 480 );
    kvmap.emplace( "r_vsync", true );
    kvmap.emplace( "r_doublebuffer", true );
    kvmap.emplace( "r_windowed", true );
    kvmap.emplace( "r_borderless", false );
    // @}
    // TODO: rest of default config
}

std::string ConfigStore::serialize()
{
    // TODO
    return "";
}

void ConfigStore::deserialize( std::string str )
{
    // TODO: clear
    deserializeAndAdd( str );
}

void ConfigStore::deserializeAndAdd( std::string str )
{
    // TODO
}

ConfigValue& ConfigStore::get( std::string k )
{
    return kvmap[k];
}

void ConfigStore::store( std::string k, i64 v )
{
    kvmap.emplace( k, v );
}

void ConfigStore::store( std::string k, std::string v )
{
    kvmap.emplace( k, v );
}
