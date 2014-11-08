#ifndef REMOVE_SYSTEM_H
#define REMOVE_SYSTEM_H

#include "System.h"

class RemoveSystem : public System
{
    public:
        virtual void update(int elapsedMs, World &);
    protected:
    private:
};

#endif
