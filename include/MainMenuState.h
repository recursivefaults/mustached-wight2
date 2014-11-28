#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "GameState.h"

class MainMenuState : public GameState
{
    public:
        MainMenuState(GameStateManager *engine);
        ~MainMenuState();
        void initialize();
        void pause();
        void resume();
        void update(int);
        void handleInput();
        void render();
    protected:
    private:
        void renderFontAt(TTF_Font *, SDL_Rect &location, const std::string &);
};

#endif
