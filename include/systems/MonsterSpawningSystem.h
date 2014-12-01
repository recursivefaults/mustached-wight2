#ifndef MONSTER_SPAWNING_SYSTEM_H
#define MONSTER_SPAWNING_SYSTEM_H

#include <random>
#include "System.h"
namespace System {
    class MonsterSpawningSystem : public System
    {
        public:
            MonsterSpawningSystem(GameStateManager *e) : System(e), bracket(0), ticksPerSpawn(5000), currentTicks(0) {};
            void update(int, World &);
        protected:
        private:
            std::default_random_engine generator;
            int bracket;
            int ticksPerSpawn;
            int currentTicks;
    };
}
#endif

