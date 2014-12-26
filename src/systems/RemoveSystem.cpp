#include "systems/RemoveSystem.h"

void System::RemoveSystem::update(int elapsedMs, World &world, Room &room)
{
    std::list<int> idsToRemove;
    for(auto deleteEntity : world.getEntitiesForType(ComponentTypes::REMOVE))
    {
        idsToRemove.push_back(deleteEntity->getId());
    }
    for(auto id : idsToRemove)
    {
        world.removeEntity(id);
    }
}
