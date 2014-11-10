#include "systems/CollisionSystem.h"
void CollisionSystem::update(int elapsedMs, World &world)
{
    for(auto collidable : world.getEntitiesForType(ComponentTypes::COLLIDABLE))
    {
       if(collidable->hasComponent(ComponentTypes::VELOCITY))
       {
           Velocity *v = (Velocity *)collidable->getComponent(ComponentTypes::VELOCITY);
           Position *p = (Position *)collidable->getComponent(ComponentTypes::POSITION);
           RenderRect *r = (RenderRect *)collidable->getComponent(ComponentTypes::RENDERRECT);
           float deltaX, deltaY = 0.0f;
           deltaX = v->dx * elapsedMs;
           deltaY = v->dy * elapsedMs;

           p->x += deltaX;
           p->y += deltaY;

           /**
            * For each other entity:
            * 1) Check to see if there AABB overlap
            * 2) Damage and remove if bullet hitting zombie
            * 3) Bump if map boundary
            * 4) Damage player if zombie hitting player and bump
            */
           for(auto entity : world.getEntitiesForType(ComponentTypes::COLLIDABLE))
           {
               if(entity == collidable) { continue; }
               Position *testPosition = (Position *)entity->getComponent(ComponentTypes::POSITION);
               RenderRect *testRender = (RenderRect *)entity->getComponent(ComponentTypes::RENDERRECT);

               bool didCollide = false;
               SDL_Rect minkowskiSquare;
               float halfWidth = r->rect.w/2;
               float halfHeight = r->rect.h/2;
               minkowskiSquare.x = testPosition->x - halfWidth;
               minkowskiSquare.y = testPosition->y - halfHeight;
               minkowskiSquare.w = testRender->rect.w + 2 * halfWidth;
               minkowskiSquare.h = testRender->rect.h + 2 * halfHeight;

               Position centerPoint = Position();
               centerPoint.x = p->x + halfWidth;
               centerPoint.y = p->y + halfHeight;

               //Minkowski Sum
               if(centerPoint.x > minkowskiSquare.x && 
                       centerPoint.x <= minkowskiSquare.x + minkowskiSquare.w &&
                       centerPoint.y >= minkowskiSquare.y &&
                       centerPoint.y <= minkowskiSquare.y + minkowskiSquare.h)
               {
                   didCollide = true;
               }

               if(didCollide == true)
               {
                   if(collidable->hasComponent(ComponentTypes::BULLET) && entity->hasComponent(ComponentTypes::MONSTER))
                   {
                       SDL_Log("Bullet hit monster!");
                       collidable->addComponent(ComponentTypes::REMOVE, new Remove());
                       Life *life = (Life *)entity->getComponent(ComponentTypes::LIFE);
                       life->damage++;
                   }
                   else if(collidable->hasComponent(ComponentTypes::PLAYERINPUT) && entity->hasComponent(ComponentTypes::MONSTER))
                   {
                       SDL_Log("Monster hit player!");
                       Collidable *collision = (Collidable *)collidable->getComponent(ComponentTypes::COLLIDABLE);
                       if(collision->currentMs == 0 || collision->currentMs >= collision->msBetweenHits)
                       {
                           Life *life = (Life *)collidable->getComponent(ComponentTypes::LIFE);
                           life->damage++;
                           collision->currentMs = 0;
                       }
                       collision->currentMs += elapsedMs;
                   }
               }
           }


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
