#include "systems/ParticleSystem.h"


void System::ParticleSystem::update(int elapsedMs, World &world, Room &room)
{
    for(auto particle : world.getEntitiesForType(ComponentTypes::PARTICLE))
    {
        Particle *particleComponent = (Particle *) particle->getComponent(ComponentTypes::PARTICLE);
        if(particleComponent->framesRemaining == 0)
        {
            particle->addComponent(ComponentTypes::REMOVE,new Remove());
        }

        Velocity *v = (Velocity *) particle->getComponent(ComponentTypes::VELOCITY);
        Position *p = (Position *) particle->getComponent(ComponentTypes::POSITION);

        p->x += elapsedMs * v->dx;
        p->y += elapsedMs * v->dy;
        particleComponent->framesRemaining--;
    }
}
