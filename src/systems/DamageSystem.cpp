#include "systems/DamageSystem.h"

void DamageSystem::update(int elapsedMs, World &world)
{
    for(auto lifer : world.getEntitiesForType(ComponentTypes::LIFE))
    {
        Life *life = (Life *) lifer->getComponent(ComponentTypes::LIFE);
        if(life->damage >= life->hp)
        {
            //That thing died.
            if(lifer->hasComponent(ComponentTypes::PLAYERINPUT))
            {
                SDL_Log("Player Died");
            }
            if(lifer->hasComponent(ComponentTypes::MONSTER))
            {
                lifer->addComponent(ComponentTypes::REMOVE, new Remove());
            }
        }
    }
            
}
