#pragma once
// Copyright (C) 2017 Sio Kreuzer. All Rights Reserved.

namespace Engine
{

class Audio
{
  public:
    static Audio& instance();
    ~Audio();
    
    void step(); // NOTE: remove if unnecessary (most likely is)
  private:
    Audio();
    // SDL mixer primitive to deal with audio
};

}
