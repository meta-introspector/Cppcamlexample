#pragma once
// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

#include "base_types.h"

namespace Engine
{

class PhysicsWorld
{
  public:
    static PhysicsWorld& instance();
    ~PhysicsWorld();
    
    void step( f64 secs );
  private:
    PhysicsWorld();
    // Bullet3 physics world goes here
};

}
