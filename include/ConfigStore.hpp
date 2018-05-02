#pragma once
// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include <string>
#include <cstdint>

// NOTE: may want something that performs better. OTOH, this might be good enough.
#include <unordered_map>

#include "base_types.h"

namespace Engine
{

typedef enum
{
    CONFIG_NULL_VALUE = 0x0,
    CONFIG_INTEGER,
    CONFIG_STRING
} ConfigValueType;

struct ConfigValue
{
    ConfigValue();
    ConfigValue( std::string str );
    ConfigValue( i64 num );
    ~ConfigValue();
    
    ConfigValueType type = CONFIG_NULL_VALUE;
    union {
        std::string* string;
        i64          integer;
    };
};

// maps from strings to config values
class ConfigStore
{
    typedef std::unordered_map< std::string, ConfigValue > map;
  public:
    static ConfigStore& instance();
    ~ConfigStore();
    
    ConfigValue& get( std::string k );
    void store( std::string k, i64 v );
    void store( std::string k, std::string v );
    
    // standard behavior for the following is to overwrite values that are already set
    
    // inserts default config (clears config beforehand)
    void defaultConfig();
    // insert default config without clearing beforehand
    void defaultConfigAdd();
    
    // serialize config to string for writing to file
    std::string serialize();
    // deserialize config from string (clears current config beforehand)
    void deserialize( std::string str );
    // deserialize config from string, but without clearing the config beforehand
    void deserializeAndAdd( std::string str );
  private:
    ConfigStore();
    map kvmap;
};

}
