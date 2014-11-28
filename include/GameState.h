#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "GameStateManager.h"

class GameStateManager;

class GameState
{
    public:
        GameState(GameStateManager *_engine) : engine(_engine) {};
        virtual ~GameState() {};
        virtual void initialize() = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
        virtual void update(int) = 0;
        virtual void handleInput() = 0;
        virtual void render() = 0;
    protected:
        GameStateManager *engine;
    private:
};

#endif
