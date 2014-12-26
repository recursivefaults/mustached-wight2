#ifndef MONSTER_SPAWNING_SYSTEM_H
#define MONSTER_SPAWNING_SYSTEM_H

#include <random>
#include "System.h"
namespace System {
    class MonsterSpawningSystem : public System
    {
        public:
            MonsterSpawningSystem(GameStateManager *e) : System(e), bracket(0) {};
            void update(int, World &, Room &);
        protected:
        private:
            int bracket;
    };
}
#endif

