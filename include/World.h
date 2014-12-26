#ifndef WORLD_H
#define WORLD_H

#include <list>
#include <map>
#include "Entity.h"
#include "Components.h"

class World
{
    /**
     * TODO: Move the gameover event to some sort of observable event
     **/
    public:
        World() : gameOver(false) {};
        void addEntity(Entity *e) {entities.push_back(e);};
        void pressKey(SDL_Keycode key) {keypresses[key] = true;}
        void removeEntity(int id);
        void clearKeys() {keypresses.clear();}
        void unPressKey(SDL_Keycode key) {keypresses[key] = false;}
        std::list<Entity *> getEntitiesForType(ComponentTypes type);
        Entity *getEntityById(int id);
        bool wasKeyPressed(SDL_Keycode key) {return keypresses[key];};
        void setGameOver(bool isOver) { gameOver = isOver;};
        bool getGameOver() {return gameOver;};
    protected:
    private:
        std::list<Entity *> entities;
        bool gameOver;
        std::map<SDL_Keycode, bool> keypresses;
};

#endif 
