#ifndef GAME_STATE_MANAGER_H
#define GAME_STATE_MANAGER_H

#include <stack>
#include "GameState.h"

class GameState;

class GameStateManager
{
    public:
        GameStateManager() : running(true) {};
        ~GameStateManager();
        /**
         * Pause the current state and put new state in focus.
         * Example: From main menu to the game or bringing up an in game menu.
         **/
        void pushState(GameState *);
        /**
         * Destroy the current state and swap it for a new one entirely.
         */
        void changeState(GameState *);
        /**
         * Destroy the current state and resume the one before it.
         **/
        void popState();
        void cleanUp();
        void handleInput();
        void update(int);
        void render();
        bool isRunning() {return running;};

    protected:
    private:
        bool running;
        std::stack<GameState *> stateStack;
};

#endif
