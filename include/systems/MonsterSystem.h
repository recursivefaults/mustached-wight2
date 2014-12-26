#ifndef MONSTER_SYSTEM_H
#define MONSTER_SYSTEM_H

#include "System.h"
#include "Vector2d.h"

namespace System {
    class MonsterSystem : public System
    {
        public:
            MonsterSystem(GameStateManager *_engine) : System(_engine) {};
            void update(int elapsedMs, World &, Room &);
        protected:
        private:
            Vector2d *getTargetedVelocity(Entity *, World &);
            Vector2d *getWanderingVelocity(Entity *, int, World &);
            void handleStun(Entity *, int);
    };
}

#endif
