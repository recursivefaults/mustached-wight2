#ifndef COLLISION_SYSETM_H
#define COLLISION_SYSETM_H

#include "System.h"
namespace System {
class CollisionSystem : public System
{
    public:
        CollisionSystem(GameStateManager *e) : System(e) {};
        virtual void update(int elapsedMs, World &, Room &);
    protected:
    private:
        bool didCollide(Entity *, Entity *, int);
        void bulletHitsMonster(Entity *, Entity *, World &);
        void playerHitsCorpse(Entity *, Entity *);
        void playerHitsMonster(Entity *, Entity *, int);
        void monsterHitsMonster(Entity *, Entity *, int);
        bool isPlayerAtExit(Entity *e, Position *p, Room &room, TileType type);
};
}

#endif
