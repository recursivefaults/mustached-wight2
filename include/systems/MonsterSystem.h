#ifndef MONSTER_SYSTEM_H
#define MONSTER_SYSTEM_H

#include "System.h"

class MonsterSystem : public System
{
    public:
        void update(int elapsedMs, World &);
    protected:
    private:
        void handleStun(Entity *, int);
};

#endif
