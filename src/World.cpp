#include "World.h"


std::vector<Entity *> World::getEntitiesForType(ComponentTypes type)
{
    std::vector<Entity *> entitiesWithComponents;

    for(auto entity : entities)
    {
        if(entity->hasComponent(type)) {
            entitiesWithComponents.push_back(entity);
        }
    }

    return entitiesWithComponents;
}
