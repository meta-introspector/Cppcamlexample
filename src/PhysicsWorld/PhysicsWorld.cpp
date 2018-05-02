// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include <PhysicsWorld.hpp>

#include <cstdlib>
#include <cstdio>

using namespace Engine;

static void quitPhysicsWorld()
{
    delete &( PhysicsWorld::instance() );
}

PhysicsWorld::PhysicsWorld()
{
    puts( "Initializing Physics World..." );
    // TODO
}

PhysicsWorld& PhysicsWorld::instance()
{
    static PhysicsWorld* p;
    if ( p ) {
        return *p;
    } else {
        p = new PhysicsWorld();
        atexit( quitPhysicsWorld );
        return *p;
    }
}

PhysicsWorld::~PhysicsWorld()
{
    puts( "Shutting down Physics World..." );
    // TODO
}

void PhysicsWorld::step( f64 secs )
{
    // TODO
}
