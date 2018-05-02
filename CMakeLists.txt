cmake_minimum_required(VERSION 3.1)
# uncomment this if you want the Makefile CMake produces to give out a lot of info about what it's doing
#set(CMAKE_VERBOSE_MAKEFILE ON)

project(Cppcamlexample)

# set options to choose from
set(CMAKE_CONFIGURATION_TYPES ${CMAKE_CONFIGURATION_TYPES} Debug Release RelWithDebInfo MinSizeRel ASAN Profile RelAggressive)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES})

### Compiler and Project settings
if(CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel" FORCE)
else()
    set (CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel" FORCE)
endif()

# NOTE: ASAN disabled because it seems to not be entirely possible to use X11/XCB/GL/whatever together with ASAN in the same application at current time (2017-09-02)
set(CMAKE_C_FLAGS                  "${CMAKE_C_FLAGS}                  -Wall -Wextra -fno-strict-aliasing -fPIC")
set(CMAKE_C_FLAGS_DEBUG            "${CMAKE_C_FLAGS_DEBUG}            -O0 -g3 -pg -fsanitize=address")
set(CMAKE_C_FLAGS_RELEASE          "${CMAKE_C_FLAGS_RELEASE}          -O3 -Werror -DNDEBUG")
set(CMAKE_C_FLAGS_RELWITHDEBINFO   "${CMAKE_C_FLAGS_RELWITHDEBINFO}   -O2 -g3 -Werror")
set(CMAKE_C_FLAGS_MINSIZEREL       "${CMAKE_C_FLAGS_MINSIZEREL}       -Os -Werror -DNDEBUG")
set(CMAKE_C_FLAGS_ASAN             "${CMAKE_C_FLAGS_ASAN}             -O0")
set(CMAKE_C_FLAGS_PROFILE          "${CMAKE_C_FLAGS_PROFILE}          -O2 -g3 -pg")
set(CMAKE_C_FLAGS_RELAGGRESSIVE    "${CMAKE_C_FLAGS_RELAGGRESSIVE}    -Ofast -Werror -DNDEBUG")

# we turn strict aliasing rules, RTTI and exceptions off. We also turn off the extra glibcpp allocator
set(CMAKE_CXX_FLAGS                "${CMAKE_CXX_FLAGS}                -Wall -Wextra -fno-strict-aliasing -fno-rtti -fno-exceptions -D GLIBCXX_FORCE_NEW -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_CXX_FLAGS_DEBUG}          -O0 -g3 -pg")
set(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE}        -O3 -Werror -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g3 -Werror")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "${CMAKE_CXX_FLAGS_MINSIZEREL}     -Os -Werror -DNDEBUG")
set(CMAKE_CXX_FLAGS_ASAN           "${CMAKE_CXX_FLAGS_ASAN}           -O0")
set(CMAKE_CXX_FLAGS_PROFILE        "${CMAKE_CXX_FLAGS_PROFILE}        -O2 -g3 -pg -fprofile-arcs")
set(CMAKE_CXX_FLAGS_RELAGGRESSIVE  "${CMAKE_CXX_FLAGS_RELAGGRESSIVE}  -Ofast -Werror -DNDEBUG")

set(CMAKE_LD_FLAGS_DEBUG           "${CMAKE_LD_FLAGS_DEBUG}           -pg -fsanitize=address -fPIC -Wl,--export-dynamic")
set(CMAKE_LD_FLAGS_RELEASE         "${CMAKE_LD_FLAGS_RELEASE}         -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--export-dynamic -fPIC")
set(CMAKE_LD_FLAGS_RELWITHDEBINFO  "${CMAKE_LD_FLAGS_RELWITHDEBINFO}  -fdata-sections -ffunction-sections -Wl,--gc-sections -fsanitize=address -Wl,--export-dynamic -fPIC")
set(CMAKE_LD_FLAGS_MINSIZEREL      "${CMAKE_LD_FLAGS_MINSIZEREL}      -fdata-sections -ffunction-sections -Wl,--export-dynamic -Wl,--gc-sections -fPIC")
set(CMAKE_LD_FLAGS_ASAN            "${CMAKE_LD_FLAGS_ASAN}            -fsanitize=address -Wl,--export-dynamic -fPIC")
set(CMAKE_LD_FLAGS_PROFILE         "${CMAKE_LD_FLAGS_PROFILE}         -pg -fprofile-arcs -Wl,--export-dynamic -fPIC")
set(CMAKE_LD_FLAGS_RELAGGRESSIVE   "${CMAKE_LD_FLAGS_RELAGGRESSIVE}   -fdata-sections -ffunction-sections -Wl,--export-dynamic -Wl,--gc-sections -fPIC")


### Find project files
file(GLOB SOURCES_AUDIO
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Audio/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Audio/*.cpp"
)
file(GLOB INCLUDES_AUDIO
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Audio/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Audio/*.hpp"
)

file(GLOB SOURCES_CONFIGSTORE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigStore/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigStore/*.cpp"
)
file(GLOB INCLUDES_CONFIGSTORE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigStore/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigStore/*.hpp"
)

# this is just a wrapper, gameplay itself is written in whatever (currently only OCaml) and (preferably) JIT compiled
file(GLOB SOURCES_GAME
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Game/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Game/*.cpp"
)
file(GLOB INCLUDES_GAME
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Game/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Game/*.hpp"
)

file(GLOB SOURCES_PHYSICSWORLD
    "${CMAKE_CURRENT_SOURCE_DIR}/src/PhysicsWorld/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/PhysicsWorld/*.cpp"
)
file(GLOB INCLUDES_PHYSICSWORLD
    "${CMAKE_CURRENT_SOURCE_DIR}/src/PhysicsWorld/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/PhysicsWorld/*.hpp"
)

file(GLOB SOURCES_RENDERER
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/*.cpp"
)
file(GLOB INCLUDES_RENDERER
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer/*.hpp"
)

file(GLOB SOURCES_SCENEGRAPH
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Scenegraph/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Scenegraph/*.cpp"
)
file(GLOB INCLUDES_SCENEGRAPH
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Scenegraph/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Scenegraph/*.hpp"
)

file(GLOB SOURCES_TOPLEVEL
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB INCLUDES_TOPLEVEL
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

file(GLOB APP_SOURCES_MAIN
  "${CMAKE_CURRENT_SOURCE_DIR}/app/*.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/app/*.cpp"
)

set(ENGINE_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include/")

execute_process(COMMAND "ocamlopt" "-where" OUTPUT_VARIABLE OCAMLC_WHERE ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)
# HACK: Need to make build system find the correct library by itself (asmrun, compiled as a static library, with PIC)
set(OCAML_RUNTIMELIBRARY "${OCAMLC_WHERE}/libasmrun_pic.a")
# HACK: OCamlC linkable object file output
file(GLOB OCAML_GAME_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/caml_src/*.ml"
)

#
# find required packages
#

include(FindPkgConfig)

# find all of SDL2
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image)
pkg_search_module(SDL2GFX REQUIRED SDL2_gfx)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
# TODO: need to find/install libBullet3, OCaml and libSQLite3 - physics world requires Bullet, game data is SQLite3-backed, saves are in SQLite3 format

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2GFX_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${ENGINE_INCLUDE_DIRS})

# NOTE: OCamlOpt/OCamlC cannot compile a shared object by itself - it fails during the linking phase, as it attempts to link a library with position-dependent code into a shared object.
set(GAME_OBJ "${PROJECT_NAME}Game")
add_custom_target(${GAME_OBJ} "ocamlopt" "-g" "-fPIC" "-linkall" "-output-obj" "${OCAML_GAME_SOURCES}" "-o" "${CMAKE_CURRENT_SOURCE_DIR}/build/game.o" WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build" VERBATIM SOURCES ${OCAML_GAME_SOURCES})

# build engine library
set(LIBRARY_NAME "${PROJECT_NAME}Engine")
add_library(${LIBRARY_NAME} SHARED ${SOURCES_AUDIO} ${SOURCES_CONFIGSTORE} ${SOURCES_GAME} ${SOURCES_PHYSICSWORLD} ${SOURCES_RENDERER} ${SOURCES_SCENEGRAPH} ${SOURCES_TOPLEVEL})
target_link_libraries(${LIBRARY_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2GFX_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${SDL2TTF_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} dl m ${OCAML_RUNTIMELIBRARY})
set_property(TARGET ${LIBRARY_NAME} PROPERTY C_STANDARD 99)
set_property(TARGET ${LIBRARY_NAME} PROPERTY CXX_STANDARD 11)

# build main executable
add_executable(${PROJECT_NAME} ${APP_SOURCES_MAIN})
add_dependencies(${PROJECT_NAME} ${LIBRARY_NAME} ${GAME_OBJ})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2GFX_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${SDL2TTF_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} dl m ${OCAML_RUNTIMELIBRARY} ${LIBRARY_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/build/game.o")

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD   99) # [90, 99, 11]
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11) # [98, 11, 14]
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
