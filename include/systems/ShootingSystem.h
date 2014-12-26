#ifndef SHOOTING_SYSTEM_H
#define SHOOTING_SYSTEM_H

#include "System.h"
namespace System {
class ShootingSystem : public System
{
    public:
        ShootingSystem(GameStateManager *e) : System(e) {};
        virtual void update(int elapsedMs, World &world, Room &room);
    protected:
    private:
        Velocity *getInitialVelocity(Entity *entity);
};
}

#endif
