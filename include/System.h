#ifndef SYSETM_H
#define SYSETM_H

#include "Entity.h"
#include "World.h"
#include "GameStateManager.h"

namespace System {

class System
{
    public:
        System() {};
        System(GameStateManager *_engine) : engine(_engine) {};
        virtual ~System() {};

        virtual void update(int elapsedMs, World &) = 0;
    protected:
        GameStateManager *engine;
    private:
};
    
}

#endif
