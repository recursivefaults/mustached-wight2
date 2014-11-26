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

void World::removeEntity(int id)
{
    std::list<Entity*>::iterator it = entities.begin();
    while(it != entities.end())
    {
        if((*it)->getId() == id)
        {
            entities.remove(*it);
            break;
        }
        else
        {
            ++it;
        }
    }
}

Entity *World::getEntityById(int id)
{
    for(auto e : entities)
    {
        if(e->getId() == id)
        {
            return e;
        }
    }
    return nullptr;
}
