#pragma once
// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include "GL_headers.hpp"

// NOTE: all the following TODOs MUST be written in *.h files and use #ifdef __cplusplus extern "C" #endif... you get what I mean. They're implemented in the src/Renderer/ folder in *.cpp files inside extern "C" blocks
// TODO: need an interface to models and textures, shared by scenegraph and renderer
// TODO: need functions to load models into engine format from files
// TODO: need function to load textures into engine format from files

namespace Engine
{

class Renderer
{
  public:
    static Renderer& instance();
    ~Renderer();

    // traverse the scenegraph, read current camera position etc. and render
    void step();
  private:
    Renderer();
    SDL_Window*    window    = nullptr;
    SDL_GLContext  glcontext = nullptr;
};

}
