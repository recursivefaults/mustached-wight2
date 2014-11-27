#ifndef GAME_STATE_MANAGER_H
#define GAME_STATE_MANAGER_H

#include <stack>

class GameStateManager
{
    public:
        GameStateManager();
        ~GameStateManager();
        void pushState(GameState *);
        GameState *popState();

    protected:
    private:
        std::stack<GameState *> stateStack;
        GameState *currentState;
};

#endif
