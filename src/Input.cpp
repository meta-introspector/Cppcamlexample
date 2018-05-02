// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include <Input.hpp>

#include <SDL_keyboard.h>
#include <SDL_mouse.h>

using namespace Engine;

InputData Engine::collectInputData()
{
    InputData out;
    memset( &out, 0, sizeof( InputData ) );
    
    out.keyboard_keys = SDL_GetKeyboardState( &out.keyboard_keycount );
    
    out.mouse_in_relative_mode = relativeMouseModeEnabled();
    u32 mouse_state =
        out.mouse_in_relative_mode
            ? SDL_GetMouseState(         &out.mouse_x, &out.mouse_y )
            : SDL_GetRelativeMouseState( &out.mouse_x, &out.mouse_y );
    out.mouse_lmb = SDL_BUTTON_LMASK & mouse_state;
    out.mouse_mmb = SDL_BUTTON_MMASK & mouse_state;
    out.mouse_rmb = SDL_BUTTON_RMASK & mouse_state;
    out.mouse_x1 = SDL_BUTTON_X1MASK & mouse_state;
    out.mouse_x2 = SDL_BUTTON_X2MASK & mouse_state;
    
    return out;
}

bool Engine::relativeMouseModeEnabled()
{
    if ( SDL_GetRelativeMouseMode() == SDL_TRUE ) {
        return true;
    } else {
        return false;
    }
}

void Engine::setRelativeMouseMode( bool enabled )
{
    if ( enabled ) {
        SDL_SetRelativeMouseMode( SDL_TRUE );
    } else {
        SDL_SetRelativeMouseMode( SDL_FALSE );
    }
}
