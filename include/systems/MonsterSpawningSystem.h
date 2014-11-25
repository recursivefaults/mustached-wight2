#ifndef MONSTER_SPAWNING_SYSTEM_H
#define MONSTER_SPAWNING_SYSTEM_H

#include "System.h"

class MonsterSpawningSystem : public System
{
    public:
        MonsterSpawningSystem(const SoundEngine *e) : System(e), bracket(0), ticksPerSpawn(5000), currentTicks(0) {};
        void update(int, World &);
    protected:
    private:
        int bracket;
        int ticksPerSpawn;
        int currentTicks;
};

#endif

