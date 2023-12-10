// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

// This is the main() - it's responsible for initializing all used libraries if they need initialization at program start (since this has to only be done once, there's a proper list of them in the CMakeLists.txt, and using the OOP approach would mean several hundred lines more code for no benefit whatsoever)

// we need atexit()
#include <cstdlib>

// printf()
#include <cstdio>

// we need assert()
#include <assert.h>


#include <OCaml.hpp>
void OCaml_shutdown()
{
    //caml_shutdown(); // This function exists, but is not exported by the OCaml runtime libraries.
}

#include "MainLoop.hpp"

int main( int argc, char** argv, char** envv )
{
    
    // TODO: OCaml runtime init/shutdown here
    printf( "Linked against OCaml version %s\n", OCAML_VERSION_STRING );
    caml_startup( argv );
    atexit( OCaml_shutdown );
    
    exit( EXIT_SUCCESS );
}
