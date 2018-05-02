// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

// This is the main() - it's responsible for initializing all used libraries if they need initialization at program start (since this has to only be done once, there's a proper list of them in the CMakeLists.txt, and using the OOP approach would mean several hundred lines more code for no benefit whatsoever)

// we need atexit()
#include <cstdlib>

// printf()
#include <cstdio>

// we need assert()
#include <assert.h>

#include <GL_headers.hpp>

#include <SDL_ttf.h>
#include <SDL_image.h>

#include <OCaml.hpp>
void OCaml_shutdown()
{
    //caml_shutdown(); // This function exists, but is not exported by the OCaml runtime libraries.
}

#include "MainLoop.hpp"

int main( int argc, char** argv, char** envv )
{
    printf( "Linked against SDL2 version %d.%d.%d\n"
          , SDL_MAJOR_VERSION
          , SDL_MINOR_VERSION
          , SDL_PATCHLEVEL
          );
    assert( SDL_Init( SDL_INIT_EVERYTHING ) == 0); // returns 0 on success
    atexit( SDL_Quit );
    
    printf( "Linked against SDL_IMG version %d.%d.%d\n"
          , SDL_IMAGE_MAJOR_VERSION
          , SDL_IMAGE_MINOR_VERSION
          , SDL_IMAGE_PATCHLEVEL
          );
    assert( IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF ) > 0); // returns non-zero bitmask on success
    atexit( IMG_Quit );
    
    printf( "Linked against SDL_TTF version %d.%d.%d\n"
          , SDL_TTF_MAJOR_VERSION
          , SDL_TTF_MINOR_VERSION
          , SDL_TTF_PATCHLEVEL
          );
    assert( TTF_Init() == 0 ); // returns 0 on success
    atexit( TTF_Quit );
    
    // TODO: OCaml runtime init/shutdown here
    printf( "Linked against OCaml version %s\n", OCAML_VERSION_STRING );
    caml_startup( argv );
    atexit( OCaml_shutdown );
    
    Engine::mainLoop();
    
    exit( EXIT_SUCCESS );
}
