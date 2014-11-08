#include "systems/CollisionSystem.h"
void CollisionSystem::update(int elapsedMs, World &world)
{
    for(auto collidable : world.getEntitiesForType(ComponentTypes::COLLIDABLE))
    {
       if(collidable->hasComponent(ComponentTypes::VELOCITY))
       {
           Velocity *v = (Velocity *)collidable->getComponent(ComponentTypes::VELOCITY);
           Position *p = (Position *)collidable->getComponent(ComponentTypes::POSITION);
           p->x += v->dx * elapsedMs;
           p->y += v->dy * elapsedMs;
       }

    }

}
