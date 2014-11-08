#ifndef SHOOTING_SYSTEM_H
#define SHOOTING_SYSTEM_H

#include "System.h"

class ShootingSystem : public System
{
    public:
        virtual void update(int elapsedMs, World &world);
    protected:
    private:
        Velocity *getInitialVelocity(Entity *entity);
};

#endif
