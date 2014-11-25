#ifndef SYSETM_H
#define SYSETM_H

#include "Entity.h"
#include "World.h"
#include "SoundEngine.h"

class System
{
    public:
        System() {};
        System(const SoundEngine *engine) : soundEngine(engine) {};
        virtual ~System() {};

        virtual void update(int elapsedMs, World &) = 0;
    protected:
        const SoundEngine *soundEngine;
    private:
};

#endif
