#ifndef DAMAGE_SYSTEM_H
#define DAMAGE_SYSTEM_H

#include "System.h"
namespace System {
class DamageSystem : public System
{
    public:
        DamageSystem(const SoundEngine *e) : System(e) {};
        void update(int, World &);
    protected:
    private:

};
}
#endif
