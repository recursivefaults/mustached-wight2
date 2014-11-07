#ifndef SYSTEM_FACTORY_H
#define SYSTEM_FACTORY_H

#include <vector>
#include "System.h"

class SystemFactory
{
    public:
        SystemFactory() {};
        ~SystemFactory() {};
        std::vector<System *> constructSystems();
    protected:
    private:

};

#endif
