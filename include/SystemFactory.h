#ifndef SYSTEM_FACTORY_H
#define SYSTEM_FACTORY_H

#include <vector>
#include "System.h"
#include "GameStateManager.h"

namespace System {
class SystemFactory
{
    public:
        SystemFactory() {};
        ~SystemFactory() {};
        std::vector<System *> constructSystems(GameStateManager *);
    protected:
    private:

};
}

#endif
