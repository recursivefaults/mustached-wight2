#ifndef WORLD_H
#define WORLD_H

#include <list>
#include <map>
#include "Entity.h"
#include "Components.h"

class World
{
    public:
        void addEntity(Entity *e) {entities.push_back(e);};
        void pressKey(SDL_Keycode key) {keypresses[key] = true;}
        void removeEntity(int id);
        void clearKeys() {keypresses.clear();}
        std::list<Entity *> getEntitiesForType(ComponentTypes type);
        bool wasKeyPressed(SDL_Keycode key) {return keypresses[key];};
    protected:
    private:
        std::list<Entity *> entities;
        std::map<SDL_Keycode, bool> keypresses;
};

#endif 
