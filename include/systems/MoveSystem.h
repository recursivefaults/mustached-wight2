#ifndef MOVE_SYSTEM_H
#define MOVE_SYSTEM_H
#include "System.h"

class MoveSystem : public System
{
    public:
        MoveSystem() {};
        ~MoveSystem() {};
        virtual void update(int elapsedMs, World &);
    protected:
    private:
};
#endif