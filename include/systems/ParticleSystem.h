#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "System.h"
namespace System {
class ParticleSystem : public System
{
    public:
        void update(int, World &, Room &);
    protected:
    private:
};
}
#endif
