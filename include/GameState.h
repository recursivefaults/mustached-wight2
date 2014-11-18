#ifndef GAME_STATE_H
#define GAME_STATE_H

enum class GameStates
{
    STATE_STARTMENU,
    STATE_PLAYING,
    STATE_PAUSEMENU,
    STATE_GAMEOVER
};

class GameState:
{
    public:
        virtual void initialize() = 0;
        virtual void run() = 0;
        virtual getState() {return _state;};
    protected:
        GameStates _state;
    private:
};

#endif
