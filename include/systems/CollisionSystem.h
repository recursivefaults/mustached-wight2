#ifndef COLLISION_SYSETM_H
#define COLLISION_SYSETM_H

#include "System.h"

class CollisionSystem : public System
{
    public:
        virtual void update(int elapsedMs, World &);
    protected:
    private:
};

#endif
