#include <math.h>
#include <random>
#include "EntityFactory.h"
#include "systems/MonsterSpawningSystem.h"

void System::MonsterSpawningSystem::update(int elapsedMs, World &world)
{

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

    currentTicks += elapsedMs;
    std::list<Entity *> corpses = world.getEntitiesForType(ComponentTypes::CORPSE);
    int newBracket = floor(corpses.size()/3);

    if(newBracket != bracket)
    {
        ticksPerSpawn -= (newBracket - bracket) * 100;
        SDL_Log("New ticks per spawn %d", ticksPerSpawn);
        bracket = newBracket;
    }
    
}
