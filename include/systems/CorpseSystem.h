#ifndef CORPSE_SYSTEM_H
#define CORPSE_SYSTEM_H

#include "System.h"
namespace System {
class CorpseSystem : public System
{
    public:
        CorpseSystem(GameStateManager *e) : System(e) {};
        void update(int, World &);
    protected:
    private:
        void handleLooting(Entity *entity, int, World &world);
        void handleBurning(Entity *entity, int, World &world);
};
}
#endif
