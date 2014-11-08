#ifndef FACING_SYSTEM_H
#define FACING_SYSTEM_H

#include "System.h"

class FacingSystem : public System
{
    public:
        virtual void update(int elapsedMs, World &world);
    protected:
    private:
};

#endif
