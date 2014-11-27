#include "systems/DamageSystem.h"
#include "EntityFactory.h"

void System::DamageSystem::update(int elapsedMs, World &world)
{
    for(auto lifer : world.getEntitiesForType(ComponentTypes::LIFE))
    {
        Life *life = (Life *) lifer->getComponent(ComponentTypes::LIFE);
        if(life->damage >= life->hp)
        {
            //That thing died.
            if(lifer->hasComponent(ComponentTypes::PLAYERINPUT))
            {
                //world.setCurrentState(GameState::GAME_OVER);
                SDL_Log("Player Died");
            }
            if(lifer->hasComponent(ComponentTypes::MONSTER))
            {
                lifer->addComponent(ComponentTypes::REMOVE, new Remove());
                //TODO: Copy constructor

                Position *oldPosition = (Position *) lifer->getComponent(ComponentTypes::POSITION);
                Position *newPosition = new Position();
                newPosition->x = oldPosition->x;
                newPosition->y = oldPosition->y;
                EntityFactory factory = EntityFactory();
                world.addEntity(factory.createCorpse(newPosition));
            }
        }
    }
            
}
