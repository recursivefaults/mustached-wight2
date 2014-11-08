#include "World.h"


std::list<Entity *> World::getEntitiesForType(ComponentTypes type)
{
    std::list<Entity *> entitiesWithComponents;

    for(auto entity : entities)
    {
        if(entity->hasComponent(type)) {
            entitiesWithComponents.push_back(entity);
        }
    }
    return entitiesWithComponents;
}


//TODO: Is this safe?
void World::removeEntity(int id)
{
    std::list<Entity*>::iterator it = entities.begin();
    for(; it != entities.end(); ++it)
    {
        if((*it)->getId() == id)
        {
            SDL_Log("Removing stale entity");
            entities.erase(it);
        }
    }
}
