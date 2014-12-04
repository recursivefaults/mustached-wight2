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
    if(counter->elapsedMs >= counter->totalMsNeeded)
    {
        std::uniform_int_distribution<int> width_generator(0,800);
        std::uniform_int_distribution<int> height_generator(0,600);

        std::uniform_real_distribution<float> flood_chance_generator(0.0f, 1.0f);
        std::uniform_int_distribution<int> flood_generator(3, 10);

        counter->elapsedMs = 0;
        int spawnCount = 1;
        if(flood_chance_generator(*engine->getRandomGenerator()) < kFloodChance)
        {
            spawnCount = flood_generator(*engine->getRandomGenerator());
            SDL_Log("Flooding the player with %d critters", spawnCount);
        }
        for(int i = 0; i < spawnCount; ++i)
        {
            Position *p = new Position();
            p->x = width_generator(*engine->getRandomGenerator());
            p->y = height_generator(*engine->getRandomGenerator());

            EntityFactory factory;
            world.addEntity(factory.createZombie(p));
        }
    }

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
    
}
