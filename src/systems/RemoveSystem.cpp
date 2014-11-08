#include "systems/RemoveSystem.h"

#include "RemovalPredicate.h"


void RemoveSystem::update(int elapsedMs, World &world)
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
