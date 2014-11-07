#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <map>
#include "Entity.h"
#include "Components.h"


class World
{
    public:
        World() {};
        ~World() {};
        void addEntity(Entity *e) {entities.push_back(e);};
        void pressKey(SDL_Keycode key) {keypresses[key] = true;}
        void clearKeys() {keypresses.clear();}
        std::vector<Entity *> getEntitiesForType(ComponentTypes type);
        bool wasKeyPressed(SDL_Keycode key) {return keypresses[key];};
    protected:
    private:
        std::vector<Entity *> entities;
        std::map<SDL_Keycode, bool> keypresses;
};

#endif 
