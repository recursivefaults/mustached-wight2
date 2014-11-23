#include "systems/ParticleSystem.h"


void ParticleSystem::update(int elapsedMs, World &world)
{
    for(auto particle : world.getEntitiesForType(ComponentTypes::PARTICLE))
    {
        Particle *particleComponent = (Particle *) particle->getComponent(ComponentTypes::PARTICLE);
        if(particleComponent->framesRemaining == 0)
        {
            SDL_Log("Cleaning up particle");
            particle->addComponent(ComponentTypes::REMOVE,new Remove());
        }

        Velocity *v = (Velocity *) particle->getComponent(ComponentTypes::VELOCITY);
        Position *p = (Position *) particle->getComponent(ComponentTypes::POSITION);

        p->x += elapsedMs * v->dx;
        p->y += elapsedMs * v->dy;
        particleComponent->framesRemaining--;
    }
}
