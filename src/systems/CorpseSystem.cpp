#include "systems/CorpseSystem.h"

void CorpseSystem::update(int elapsedMs, World &world)
{
    for(auto oncorpse : world.getEntitiesForType(ComponentTypes::ONCORPSE))
    {
        if(oncorpse->hasComponent(ComponentTypes::PLAYERINPUT))
        {
            if(world.wasKeyPressed(SDLK_q))
            {
                handleLooting(oncorpse, elapsedMs, world);

            }
            else if(world.wasKeyPressed(SDLK_e))
            {
                handleBurning(oncorpse, elapsedMs, world);
            }
            else
            {
                oncorpse->removeComponent(ComponentTypes::LOOTINGCORPSE);
                oncorpse->removeComponent(ComponentTypes::BURNINGCORPSE);
            }

        }

    }
}

void CorpseSystem::handleLooting(Entity *entity, int elapsed,  World &world)
{
    if(!entity->hasComponent(ComponentTypes::LOOTINGCORPSE))
    {
        entity->addComponent(ComponentTypes::LOOTINGCORPSE, new LootingCorpse());
    }
    LootingCorpse *timed = (LootingCorpse *) entity->getComponent(ComponentTypes::LOOTINGCORPSE);
    timed->elapsedMs += elapsed;

    if(timed->elapsedMs >= timed->totalMsNeeded)
    {
        Ammo *ammo = (Ammo *) entity->getComponent(ComponentTypes::AMMO);
        ammo->ammo += 5;
        SDL_Log("Updating ammo to %d", ammo->ammo);

        OnCorpse *c = (OnCorpse *)entity->getComponent(ComponentTypes::ONCORPSE);
        SDL_Log("Deleting corpse %d", c->corpseEntityId);
        
        entity->removeComponent(ComponentTypes::LOOTINGCORPSE);
        entity->removeComponent(ComponentTypes::ONCORPSE);
        world.removeEntity(c->corpseEntityId);
    }
}

void CorpseSystem::handleBurning(Entity *entity, int elapsed, World &world)
{
    if(!entity->hasComponent(ComponentTypes::BURNINGCORPSE))
    {
        entity->addComponent(ComponentTypes::BURNINGCORPSE, new BurningCorpse());
    }
    TimedComponent *timed = (TimedComponent *) entity->getComponent(ComponentTypes::BURNINGCORPSE);
    timed->elapsedMs += elapsed;

    if(timed->elapsedMs >= timed->totalMsNeeded)
    {

        OnCorpse *c = (OnCorpse *)entity->getComponent(ComponentTypes::ONCORPSE);
        SDL_Log("Deleting corpse %d", c->corpseEntityId);
        
        entity->removeComponent(ComponentTypes::BURNINGCORPSE);
        entity->removeComponent(ComponentTypes::ONCORPSE);
        world.removeEntity(c->corpseEntityId);
    }
}
