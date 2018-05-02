// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include <Scenegraph.hpp>

#include <cstdio>

using namespace Engine;

Scenegraph::Scenegraph()
{
    puts( "Initializing Scenegraph..." );
    // TODO
}

Scenegraph& Scenegraph::instance()
{
    static Scenegraph* s;
    if ( s ) {
        return *s;
    } else {
        s = new Scenegraph();
        return *s;
    }
}

Scenegraph::~Scenegraph()
{
    puts( "Shutting down Scenegraph..." );
    // TODO
}
