#include "systems/CollisionSystem.h"
#include "EntityFactory.h"
#include "Tile.h"
#include <cmath>

void System::CollisionSystem::update(int elapsedMs, World &world, Room &room)
{
    for(auto collidable : world.getEntitiesForType(ComponentTypes::COLLIDABLE))
    {
       if(collidable->hasComponent(ComponentTypes::VELOCITY))
       {
           Velocity *v = (Velocity *)collidable->getComponent(ComponentTypes::VELOCITY);
           Position *p = (Position *)collidable->getComponent(ComponentTypes::POSITION);
           float deltaX, deltaY = 0.0f;
           deltaX = v->dx * elapsedMs;
           deltaY = v->dy * elapsedMs;

           bool collided = false;

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

               //Minkowski Sum
               if(didCollide(collidable, entity, elapsedMs))
               {
                   bulletHitsMonster(collidable, entity, world);
                   playerHitsCorpse(collidable, entity);
                   playerHitsMonster(collidable, entity, elapsedMs);
                   collided = true;
               }
           }
           //Remove the onCorpse if it's there.
           if(collidable->hasComponent(ComponentTypes::PLAYERINPUT) && collidable->hasComponent(ComponentTypes::ONCORPSE) && !collided)
           {
               SDL_Log("Player %d, no longer on corpse", collidable->getId());
               collidable->removeComponent(ComponentTypes::ONCORPSE);
           }
               

           p->x += deltaX;
           p->y += deltaY;


           //Check world boundaries
           bool remove = false;
           if(p->x >= 800) {
               if(collidable->hasComponent(ComponentTypes::BULLET)) {
                   remove = true;
               }
               if(isPlayerAtExit(collidable, p, room, TileType::EAST_EXIT)) {
               }
               p->x = 800 - 16;
           }
           if(p->x <= 0) {
               if(collidable->hasComponent(ComponentTypes::BULLET)) {
                   remove = true;
               }
               if(isPlayerAtExit(collidable, p, room, TileType::WEST_EXIT)) {
               }
               p->x = 0;
           }

           if(p->y >= 600) {
               if(collidable->hasComponent(ComponentTypes::BULLET)) {
                   remove = true;
               }
               if(isPlayerAtExit(collidable, p, room, TileType::SOUTH_EXIT)) {
               }
               p->y = 600 - 16;
           }
           if(p->y <= 0) {
               if(collidable->hasComponent(ComponentTypes::BULLET)) {
                   remove = true;
               }
               if(isPlayerAtExit(collidable, p, room, TileType::NORTH_EXIT)) {
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

bool System::CollisionSystem::didCollide(Entity *first, Entity *second, int elapsedMs)
{
    Velocity *v = (Velocity *)first->getComponent(ComponentTypes::VELOCITY);
    Position *p = (Position *)first->getComponent(ComponentTypes::POSITION);
    RenderRect *r = (RenderRect *)first->getComponent(ComponentTypes::RENDERRECT);

    float deltaX, deltaY = 0.0f;
    deltaX = abs(v->dx * elapsedMs);
    deltaY = abs(v->dy * elapsedMs);

    SDL_Rect updated = {p->x, p->y, static_cast<int>(r->rect.w + deltaX), static_cast<int>(r->rect.h + deltaY)};

    Position *testPosition = (Position *)second->getComponent(ComponentTypes::POSITION);
    RenderRect *testRender = (RenderRect *)second->getComponent(ComponentTypes::RENDERRECT);

    SDL_Rect minkowskiSquare;
    float halfWidth = updated.w/2;
    float halfHeight = updated.h/2;

    minkowskiSquare.x = testPosition->x - halfWidth;
    minkowskiSquare.y = testPosition->y - halfHeight;
    minkowskiSquare.w = testRender->rect.w + 2 * halfWidth;
    minkowskiSquare.h = testRender->rect.h + 2 * halfHeight;

    Position centerPoint = Position();
    centerPoint.x = p->x + r->rect.w/2;
    centerPoint.y = p->y + r->rect.h/2;

    return centerPoint.x >= minkowskiSquare.x && 
            centerPoint.x <= minkowskiSquare.x + minkowskiSquare.w &&
            centerPoint.y >= minkowskiSquare.y &&
            centerPoint.y <= minkowskiSquare.y + minkowskiSquare.h;
}

void System::CollisionSystem::bulletHitsMonster(Entity *first, Entity *second, World &world)
{
    if(first->hasComponent(ComponentTypes::BULLET) && 
            second->hasComponent(ComponentTypes::MONSTER) && 
            !first->hasComponent(ComponentTypes::REMOVE))
    {
        SDL_Log("Bullet hit monster!");
        first->addComponent(ComponentTypes::REMOVE, new Remove());
        Life *life = (Life *)second->getComponent(ComponentTypes::LIFE);
        life->damage++;

        //Stun the monster
        second->addComponent(ComponentTypes::STUNNED, new Stunned());

        EntityFactory factory = EntityFactory();
        //Create particles
        for(int i = 0; i < 4; i++)
        {
            Position *startP = (Position *) second->getComponent(ComponentTypes::POSITION);
            Velocity *startV = (Velocity *) first->getComponent(ComponentTypes::VELOCITY);

            world.addEntity(factory.createBloodParticle(startP, startV));
        }
    }
}

void System::CollisionSystem::playerHitsCorpse(Entity *first, Entity *second)
{
    if(first->hasComponent(ComponentTypes::PLAYERINPUT) && second->hasComponent(ComponentTypes::CORPSE))
    {
        if(!first->hasComponent(ComponentTypes::ONCORPSE))
        {
            OnCorpse *c = new OnCorpse();
            c->corpseEntityId = second->getId();
            SDL_Log("Standing on corpse: %d", c->corpseEntityId);
            first->addComponent(ComponentTypes::ONCORPSE, c);
        }
    }
}

void System::CollisionSystem::playerHitsMonster(Entity *first, Entity *second, int elapsedMs)
{
    if(first->hasComponent(ComponentTypes::PLAYERINPUT) && second->hasComponent(ComponentTypes::MONSTER))
    {
        Collidable *collision = (Collidable *)first->getComponent(ComponentTypes::COLLIDABLE);
        if(collision->currentMs == 0 || collision->currentMs >= collision->msBetweenHits)
        {
            SDL_Log("Monster hit player!");
            Life *life = (Life *)first->getComponent(ComponentTypes::LIFE);
            life->damage++;
            collision->currentMs = 0;
            second->addComponent(ComponentTypes::STUNNED, new Stunned());
            engine->getSoundEngine()->playSound("Hurt.wav", 1);
        }
        collision->currentMs += elapsedMs;
    }
}

bool System::CollisionSystem::isPlayerAtExit(Entity *e, Position *p, Room &room, TileType type)
{
    if(e->hasComponent(ComponentTypes::PLAYERINPUT)) {
        Position newP; 
        newP.x = p->x;
        newP.y = p->y;
        if(p->x > 800) newP.x = 800;
        if(p->x < 0) newP.x = 0;
        if(p->y < 0) newP.y = 0;
        if(p->y > 600) newP.y = 600;
        if(room.getTileAtPoint(newP.x, newP.y)->getFlag() == type) {
            SDL_Log("EXIT");
            return true;
        }
    }
    return false;
}
