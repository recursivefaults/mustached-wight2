#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "Entity.h"

class EntityFactory
{
    public:
        Entity *createPlayer();
        Entity *createBullet(Position *, Velocity *);
        Entity *createZombie(Position *);
    protected:
    private:
};

#endif
