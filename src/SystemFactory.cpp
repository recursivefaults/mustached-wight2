#include "SystemFactory.h"
#include "systems/MoveSystem.h"
#include "systems/CollisionSystem.h"


std::vector<System *> SystemFactory::constructSystems()
{
    std::vector<System *> systems;
    systems.push_back(new MoveSystem());
    systems.push_back(new CollisionSystem());
    return systems;
}
