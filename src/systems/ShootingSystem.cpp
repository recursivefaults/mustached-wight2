#include "systems/ShootingSystem.h"
#include "Constants.h"
#include "EntityFactory.h"

void ShootingSystem::update(int elapsedMs, World &world)
{
    for(auto entity : world.getEntitiesForType(ComponentTypes::CANSHOOT))
    {
        if(world.wasKeyPressed(SDLK_SPACE))
        {
            EntityFactory factory = EntityFactory();

            Position *initialPosition = new Position();
            Position *p = (Position *)entity->getComponent(ComponentTypes::POSITION);
            initialPosition->x = p->x;
            initialPosition->y = p->y;
            
            Entity *bullet = factory.createBullet(initialPosition, getInitialVelocity(entity));
            
            world.addEntity(bullet);
        }

    }
}

Velocity *ShootingSystem::getInitialVelocity(Entity *entity)
{
    Velocity *initialVelocity = new Velocity();
    initialVelocity->dx = 0.0f;
    initialVelocity->dy = 0.0f;
    if(entity->hasComponent(ComponentTypes::NORTHFACING))
    {
        initialVelocity->dy = -kBulletVelocity;
    }
    if(entity->hasComponent(ComponentTypes::SOUTHFACING))
    {
        initialVelocity->dy = kBulletVelocity;
    }
    if(entity->hasComponent(ComponentTypes::WESTFACING))
    {
        initialVelocity->dx = -kBulletVelocity;
    }
    if(entity->hasComponent(ComponentTypes::EASTFACING))
    {
        initialVelocity->dx = kBulletVelocity;
    }
    return initialVelocity;
}
