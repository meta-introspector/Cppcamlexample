// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include <Audio.hpp>

#include <cstdlib>
#include <cstdio>

using namespace Engine;

static void quitAudioSubsystem()
{
    delete &( Audio::instance() );
}

Audio::Audio()
{
    puts( "Initializing Audio..." );
    // TODO
}

Audio::~Audio()
{
    puts( "Shutting down Audio subsystem..." );
    // TODO
}

Audio& Audio::instance()
{
    static Audio* a;
    if ( a ) {
        return *a;
    } else {
        a = new Audio();
        atexit( quitAudioSubsystem );
        return *a;
    }
}

void Audio::step()
{
    // TODO
}
