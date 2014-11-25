#ifndef WORLD_H
#define WORLD_H

#include <list>
#include <map>
#include "Entity.h"
#include "Components.h"
#include "SoundEngine.h"

enum class GameState
{
    MENU,
    PLAYING,
    GAME_OVER
};

class World
{
    public:
        GameState getCurrentState() { return currentState; };
        void setCurrentState(GameState nextState) { currentState = nextState; };
        void addEntity(Entity *e) {entities.push_back(e);};
        void pressKey(SDL_Keycode key) {keypresses[key] = true;}
        void removeEntity(int id);
        void clearKeys() {keypresses.clear();}
        void unPressKey(SDL_Keycode key) {keypresses[key] = false;}
        std::list<Entity *> getEntitiesForType(ComponentTypes type);
        Entity *getEntityById(int id);
        bool wasKeyPressed(SDL_Keycode key) {return keypresses[key];};
        void setSoundEngine(SoundEngine &engine) {soundEngine = &engine;};
        SoundEngine *getSoundEngine() {return soundEngine;};
    protected:
    private:
        SoundEngine *soundEngine;
        GameState currentState;
        std::list<Entity *> entities;
        std::map<SDL_Keycode, bool> keypresses;
};

#endif 
