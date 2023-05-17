#ifndef _ENGINE_H_
#define _ENGINE_H_
#include <SDL2/SDL.h>
#include "World.hpp"

namespace Engine
{
    bool Init();
    void Run();
    World &GetWorld();
}

#endif