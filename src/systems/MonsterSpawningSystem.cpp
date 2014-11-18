#include <math.h>
#include <random>
#include "EntityFactory.h"
#include "systems/MonsterSpawningSystem.h"

void MonsterSpawningSystem::update(int elapsedMs, World &world)
{
    currentTicks += elapsedMs;
    std::list<Entity *> corpses = world.getEntitiesForType(ComponentTypes::CORPSE);
    int bracket = floor(corpses.size()/3);

    if(currentTicks >= ticksPerSpawn)
    {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> width_generator(0,800);
        std::uniform_int_distribution<int> height_generator(0,600);
        currentTicks = 0;
        Position *p = new Position();
        p->x = width_generator(generator);
        p->y = height_generator(generator);

        EntityFactory factory;
        world.addEntity(factory.createZombie(p));
    }

    
    
    

}
