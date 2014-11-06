#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include "Components.h"

static int STATIC_COUNTER = 0;

class Entity
{
    public:
        Entity() : _id(STATIC_COUNTER++) {}; 
        ~Entity();
        Component* getComponent(ComponentTypes type);
        bool hasComponent(ComponentTypes);
        void addComponent(ComponentTypes type, Component *component);
        void removeComponent(ComponentTypes type);
    protected:
    private:
        int _id;
        std::map<ComponentTypes, Component*> components;
};

#endif
