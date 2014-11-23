#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include <random>
#include "Entity.h"

class EntityFactory
{
    public:
        EntityFactory();
        Entity *createPlayer();
        Entity *createBullet(Position *, Velocity *);
        Entity *createZombie(Position *);
        Entity *createCorpse(Position *);
        Entity *createBloodParticle(Position *, Velocity *);
    protected:
    private:
        std::uniform_int_distribution<int> lifeDistribution;
        std::uniform_int_distribution<int> frameDistribution;
        std::uniform_int_distribution<int> ammoDistribution;
        std::uniform_real_distribution<float> velocityDistribution;
        std::default_random_engine generator;
};

#endif
