#ifndef SYSETM_H
#define SYSETM_H

#include "Entity.h"
#include "World.h"

class System
{
    public:
        System() {};
        virtual ~System() {};

        virtual void update(int elapsedMs, World &) = 0;
    protected:
    private:
};

#endif
