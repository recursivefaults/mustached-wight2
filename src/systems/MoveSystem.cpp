#include "systems/MoveSystem.h"
#include "Constants.h"

void System::MoveSystem::update(int elapsedMs, World &world, Room &room)
{
    //TODO: Change this to something else.. enemies move different.
    for(auto entity : world.getEntitiesForType(ComponentTypes::PLAYERINPUT))
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
