// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include <Game.hpp>

#include <cstdio>
#include <cstdlib>

using namespace Engine;

static void quitOCamlGame()
{
    delete &( OCamlGame::instance() );
}

OCamlGame::OCamlGame()
{
    puts( "Initializing Game Code interface..." );
    memset( &current_input_data, 0, sizeof( InputData ) );
    
    init_fn = (value*)caml_named_value( "init_fn" );
    assert( init_fn );
    
    shutdown_fn = (value*)caml_named_value( "shutdown_fn" );
    assert( shutdown_fn );
    
    step_fn = (value*)caml_named_value( "step_fn" );
    assert( step_fn );
    
    caml_callback( *init_fn, Val_unit );
}

OCamlGame& OCamlGame::instance()
{
    static OCamlGame* o;
    if ( o ) {
        return *o;
    } else {
        o = new OCamlGame();
        atexit( quitOCamlGame );
        return *o;
    }
}

OCamlGame::~OCamlGame()
{
    puts( "Shutting down Game Code interface..." );
    caml_callback( *shutdown_fn, Val_unit );
}

void OCamlGame::step( InputData input )
{
    current_input_data = input;
    caml_callback( *step_fn, Val_unit );
}

InputData OCamlGame::currentInputData()
{
    return current_input_data;
}

void OCamlGame::minorGC()
{
    // TODO
}

void OCamlGame::majorGC()
{
    // TODO
}
