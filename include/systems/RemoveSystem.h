#ifndef REMOVE_SYSTEM_H
#define REMOVE_SYSTEM_H

#include "System.h"
namespace System {
class RemoveSystem : public System
{
    public:
        virtual void update(int elapsedMs, World &, Room &);
    protected:
    private:
};
}

#endif
