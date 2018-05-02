#pragma once
// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

namespace Engine
{

class Scenegraph
{
  public:
    static Scenegraph& instance();
    ~Scenegraph();

    // TODO: Renderer needs some methods to traverse scenegraph
  private:
    Scenegraph();
    // TODO: steal DOOM 3's scenegraph & scenegraph traversal implementation
};

}
