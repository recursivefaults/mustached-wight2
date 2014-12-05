#include <math.h>
#include <random>
#include "EntityFactory.h"
#include "Constants.h"
#include "systems/MonsterSpawningSystem.h"

void System::MonsterSpawningSystem::update(int elapsedMs, World &world)
{
    Entity *corpseCounter = world.getEntitiesForType(ComponentTypes::CORPSE_COUNTER).front();

    CorpseCounter *counter = (CorpseCounter *) corpseCounter->getComponent(ComponentTypes::CORPSE_COUNTER);

    counter->elapsedMs += elapsedMs;
    
    std::list<Entity *> corpses = world.getEntitiesForType(ComponentTypes::CORPSE);
    int newBracket = corpses.size();

    if(newBracket != bracket)
    {
        int newTotal = counter->totalMsNeeded - (newBracket - bracket) * 150;
        if(newTotal < 1000)
        {
            newTotal = 1000;
        }
        counter->totalMsNeeded = newTotal;
        SDL_Log("New ticks per spawn %d", counter->totalMsNeeded);
        bracket = newBracket;
    }

    if(counter->elapsedMs >= counter->totalMsNeeded)
    {

        std::uniform_real_distribution<float> flood_chance_generator(0.0f, 1.0f);
        std::uniform_int_distribution<int> flood_generator(3, 5);

        counter->elapsedMs = 0;
        int spawnCount = 1;
        if(flood_chance_generator(*engine->getRandomGenerator()) < kFloodChance)
        {
            spawnCount = flood_generator(*engine->getRandomGenerator());
            SDL_Log("Flooding the player with %d critters", spawnCount);
        }
        for(int i = 0; i < spawnCount; ++i)
        {

            EntityFactory factory;
            world.addEntity(factory.createZombie(getSpawnPosition()));
        }
    }
}

Position *System::MonsterSpawningSystem::getSpawnPosition()
{

    std::uniform_int_distribution<int> boolGenerator(0, 1);
    std::uniform_int_distribution<int> width_generator(0,800);
    std::uniform_int_distribution<int> height_generator(0,600);
    Position *p = new Position();
    if(boolGenerator(*engine->getRandomGenerator()) == 1)
    {
        //Spawn horizontally
        
        p->x = width_generator(*engine->getRandomGenerator());
        p->y = 600;
        if(boolGenerator(*engine->getRandomGenerator()) == 1)
        {
            //Spawn top
            p->y = 0;
        }
    }
    else
    {
        p->y = height_generator(*engine->getRandomGenerator());
        p->x = 800;
        if(boolGenerator(*engine->getRandomGenerator()) == 1)
        {
            //Spawn left
            p->y = 0;
        }
    }
    return p;
}
