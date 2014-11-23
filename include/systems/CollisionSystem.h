#ifndef COLLISION_SYSETM_H
#define COLLISION_SYSETM_H

#include "System.h"

class CollisionSystem : public System
{
    public:
        virtual void update(int elapsedMs, World &);
    protected:
    private:
        bool didCollide(Entity *, Entity *, int);
        void bulletHitsMonster(Entity *, Entity *, World &);
        void playerHitsCorpse(Entity *, Entity *);
        void playerHitsMonster(Entity *, Entity *, int);
        void monsterHitsMonster(Entity *, Entity *, int);
};

#endif
