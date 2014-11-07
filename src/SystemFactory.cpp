#include "SystemFactory.h"
#include "systems/MoveSystem.h"


std::vector<System *> SystemFactory::constructSystems()
{
    std::vector<System *> systems;
    systems.push_back(new MoveSystem());
    return systems;
}
