#include "Entity.h"

Component* Entity::getComponent(ComponentTypes type)
{
    std::map<ComponentTypes, Component*>::iterator it = components.find(type);
    if(it == components.end()) {
        return nullptr;
    }
    return it->second;
}
bool Entity::hasComponent(ComponentTypes type)
{
    std::map<ComponentTypes, Component*>::iterator it = components.find(type);
    return it == components.end();
}
void Entity::addComponent(ComponentTypes type, Component *component)
{
    components[type] = component;
}
void Entity::removeComponent(ComponentTypes type)
{
}
