#ifndef FACING_SYSTEM_H
#define FACING_SYSTEM_H

#include "System.h"
namespace System {
class FacingSystem : public System
{
    public:
        virtual void update(int elapsedMs, World &world);
    protected:
    private:
};
}

#endif
