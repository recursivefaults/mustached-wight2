#include "systems/MoveSystem.h"
#include "Constants.h"

void MoveSystem::update(int elapsedMs, World &world)
{
    //TODO: Change this to something else.. enemies move different.
    for(auto entity : world.getEntitiesForType(ComponentTypes::VELOCITY))
    {
        Velocity *v = (Velocity *) entity->getComponent(ComponentTypes::VELOCITY);
        v->dx = 0.0f;
        v->dy = 0.0f;
        if(world.wasKeyPressed(SDLK_a)) {
            v->dx = -kMoveVelocity;
        }
        if(world.wasKeyPressed(SDLK_d)) {
            v->dx = kMoveVelocity;
        }
        if(world.wasKeyPressed(SDLK_w)) {
            v->dy = -kMoveVelocity;
        }
        if(world.wasKeyPressed(SDLK_s)) {
            v->dy = kMoveVelocity;
        }
    }
}
