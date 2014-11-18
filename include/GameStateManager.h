#ifndef GAME_STATE_MANAGER_H
#define GAME_STATE_MANAGER_H

class GameStateManager
{
    public:
        GameStateManager();
        ~GameStateManager();

    protected:
    private:
        GameState *currentState;
};

#endif
