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

           //Check world boundaries
           bool remove = false;
           if(p->x >= 800) {
               if(collidable->hasComponent(ComponentTypes::BULLET)) {
                   remove = true;
               }
               p->x = 800 - 16;
           }
           if(p->x <= 0) {
               if(collidable->hasComponent(ComponentTypes::BULLET)) {
                   remove = true;
               }
               p->x = 0;
           }

           if(p->y >= 600) {
               if(collidable->hasComponent(ComponentTypes::BULLET)) {
                   remove = true;
               }
               p->y = 600 - 16;
           }
           if(p->y <= 0) {
               if(collidable->hasComponent(ComponentTypes::BULLET)) {
                   remove = true;
               }
               p->y = 0;
           }
           if(remove) 
           {
               collidable->addComponent(ComponentTypes::REMOVE, new Remove());
           }
       }
    }
}
