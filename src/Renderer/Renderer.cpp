// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include <Renderer.hpp>
#include <ConfigStore.hpp>
#include <base_types.h>

#include <cstdlib>
#include <cstdio>
#include <cassert>

using namespace Engine;

static void quitRenderer()
{
    delete &( Renderer::instance() );
}

struct RendererConfig
{
    ConfigValue& r_width; // renderer and window width
    ConfigValue& r_height; // renderer and window height
    ConfigValue& r_vsync; // true: use vsync
    ConfigValue& r_doublebuffer; // true: use double buffering
    ConfigValue& r_borderless; // true: borderless ("fake" fullscreen mode), false: r_windowed gets considered
    ConfigValue& r_windowed; // true: windowed, false: exclusive ("true") fullscreen
};

static RendererConfig* config;

static u32 video_mode()
{
    u32 win_flags = 0;
    
    if ( config -> r_borderless.integer ) {
        win_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP; // set "fake" fullscreen
    } else if ( !( config -> r_windowed.integer ) ) {
        win_flags |= SDL_WINDOW_FULLSCREEN; // set "true" fullscreen
    } else {
        win_flags |= SDL_WINDOW_RESIZABLE; // set window to be resizable
    }
    
    return win_flags;
}

Renderer::Renderer()
{
    puts( "Initializing Renderer..." );
    ConfigStore& c = ConfigStore::instance();
    // fill in our config
    config = new RendererConfig { c.get( "r_width" )
                                , c.get( "r_height" )
                                , c.get( "r_vsync" )
                                , c.get( "r_doublebuffer" )
                                , c.get( "r_borderless" )
                                , c.get( "r_windowed" )
                                };
    
    u32 win_flags = SDL_WINDOW_OPENGL
                  | SDL_WINDOW_SHOWN
                  | SDL_WINDOW_INPUT_FOCUS
                  | video_mode()
                  ;
    window = SDL_CreateWindow( "OpenChernobyl"
                             , SDL_WINDOWPOS_CENTERED
                             , SDL_WINDOWPOS_CENTERED
                             , config -> r_width.integer
                             , config -> r_height.integer
                             , win_flags
                             );
    
    // using GL2.1
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    
    if ( config -> r_doublebuffer.integer ) {
        SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    } else {
        SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 0 );
    }
    
    glcontext = SDL_GL_CreateContext( window );
    assert( glcontext );
    
    GLenum glew_init_error = glewInit();
    if ( glew_init_error != GLEW_OK ) {
        printf( "Error while initializing GLEW: %s\n"
              , glewGetErrorString( glew_init_error )
              );
        exit( EXIT_FAILURE );
    }
    
    if ( config -> r_vsync.integer ) {
        SDL_GL_SetSwapInterval( 1 );
    } else {
        SDL_GL_SetSwapInterval( 0 );
    }
    
    // enable miscellaneous needed features
    glEnable( GL_TEXTURE_2D ); // render 2D textures directly to screen
    glEnable( GL_DEPTH_TEST ); // z-culling
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glPushMatrix();
    
    glShadeModel( GL_SMOOTH ); // set smooth shading -> TODO: determine if this should be an option
    
    // TODO: further bits of init - such as saving references to all config variables to local struct
}

Renderer& Renderer::instance()
{
    static Renderer* r;
    if ( r ) {
        return *r;
    } else {
        r = new Renderer();
        atexit( quitRenderer );
        return *r;
    }
}

Renderer::~Renderer()
{
    puts( "Shutting down Renderer..." );
    // NOTE: any renderer-attached objects may have to be destroyed here?
    SDL_GL_DeleteContext( glcontext );
    SDL_DestroyWindow( window );
    delete config;
}

// TODO: investigate if clearing colors is really necessary (most likely not, since we have a skybox anyway - may wish to just render skybox instead of clearing?)
static void clear()
{
    glClearColor( 0.0f // R
                , 0.0f // G
                , 0.0f // B
                , 1.0f // A
                );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    // TODO: move camera to the correct position
    // TODO: record camera position, or record which scenegraph/physical object it's tied to (that'd be the player objects)
}

static void present( SDL_Window* window )
{
    if ( config -> r_doublebuffer.integer ) {
        SDL_GL_SwapWindow( window );
    }
}

void Renderer::step()
{
    clear();
    // TODO: traverse scenegraph and draw
    present( window );
}
