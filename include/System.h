#ifndef SYSETM_H
#define SYSETM_H

#include "Entity.h"
#include <vector>

class System
{
    public:
        System() {};
        virtual ~System() {};

        virtual void update(int elapsedMs, std::vector<Entity *> entities) = 0;
    protected:
    private:
};

#endif
