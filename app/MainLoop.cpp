// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include "MainLoop.hpp"

#include <base_types.h>

#include <GL_headers.hpp>

#include <Game.hpp>

#include <ConfigStore.hpp>
#include <PhysicsWorld.hpp>
#include <Audio.hpp>
#include <Renderer.hpp>
#include <Scenegraph.hpp>

using namespace Engine;

void Engine::mainLoop()
{
    ConfigStore&  config     = ConfigStore::instance();
    PhysicsWorld& physics    = PhysicsWorld::instance();
    Audio&        audio      = Audio::instance();
    Renderer&     renderer   = Renderer::instance();
    Scenegraph&   scenegraph = Scenegraph::instance();
    OCamlGame&    ocamlgame  = OCamlGame::instance(); // FIXME: problem in ocamlgame constructor
    
    u32 curr_ticks = 0;
    u32 old_ticks  = 0;
    u32 tick_delta = 0;
    for( ;; ) {
        old_ticks = curr_ticks;
        curr_ticks = SDL_GetTicks();
        tick_delta = curr_ticks - old_ticks;
        f64 tick_delta_in_seconds = ((f64) 1000.0) * ((f64) tick_delta);
        
        // let's make sure we actually fucking quit when receiving a quit event, like ALT+F4 or CTRL-C
        SDL_Event ev;
        while ( SDL_PollEvent( &ev ) ) {
            if ( ev.type == SDL_QUIT ) {
                exit( EXIT_SUCCESS );
            }
        }
        
        ocamlgame.step( collectInputData() );
        physics.step( tick_delta_in_seconds );
        audio.step();
        renderer.step();
    }
}
