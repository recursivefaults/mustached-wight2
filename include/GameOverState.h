#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H

#include "GameState.h"

class GameOverState : public GameState
{
    public:
        GameOverState(GameStateManager *engine);
        ~GameOverState();
        void initialize();
        void pause();
        void resume();
        void update(int);
        void handleInput();
        void render();
    protected:
    private:
};

#endif
