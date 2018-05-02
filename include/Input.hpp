#pragma once
// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include "base_types.h"

namespace Engine
{

// NOTE: this struct *has* to be kept a POD and has to have a mirror type in the gameplay code. Thus, if you modify this, you break stuff.
struct InputData
{
    // we're interested only in mouse position, relative mouse position,
    // and keyboard keys
    const u8* keyboard_keys;     // indexed by SDL_SCANCODE_*
    int keyboard_keycount;
    // mouse x/y coords, if in relative mode - x/y coords since last sampled
    int mouse_x;
    int mouse_y;
    // info about input system state
    bool mouse_in_relative_mode;
    // mouse buttons
    bool mouse_lmb;
    bool mouse_mmb;
    bool mouse_rmb;
    bool mouse_x1;
    bool mouse_x2;
};

InputData collectInputData();

bool relativeMouseModeEnabled();
void setRelativeMouseMode( bool on );

}
