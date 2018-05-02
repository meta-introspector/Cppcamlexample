#pragma once
// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include "Input.hpp"

#include "OCaml.hpp"

namespace Engine
{

// wraps OCaml game code
class OCamlGame
{
  public:
    static OCamlGame& instance();
    ~OCamlGame();

    void step( InputData input );
    
    // minor GC takes a very short amount of time, major GC is something you'd use during loading screens because it takes a while
    void minorGC();
    void majorGC();
    
    InputData currentInputData();
  private:
    OCamlGame();
    InputData current_input_data;
    value*    init_fn     = nullptr;
    value*    shutdown_fn = nullptr;
    value*    step_fn     = nullptr;
};

}

extern "C" Engine::InputData currentInputData();
