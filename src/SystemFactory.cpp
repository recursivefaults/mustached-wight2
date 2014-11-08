#include "SystemFactory.h"
#include "systems/MoveSystem.h"
#include "systems/CollisionSystem.h"
#include "systems/FacingSystem.h"
#include "systems/ShootingSystem.h"
#include "systems/RemoveSystem.h"


std::vector<System *> SystemFactory::constructSystems()
{
    std::vector<System *> systems;
    systems.push_back(new MoveSystem());
    systems.push_back(new FacingSystem());
    systems.push_back(new ShootingSystem());
    systems.push_back(new CollisionSystem());
    systems.push_back(new RemoveSystem());
    return systems;
}
