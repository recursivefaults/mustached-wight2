#ifndef GAME_H
#define GAME_H

#include "Graphics.h"
#include "Entity.h"
#include <vector>

class Game
{
    public:
        Game();
        ~Game();
        void start();
    protected:
    private:
        void handleInput(SDL_Event &e);
        void update(int elapsedMs);
        void render();
        Graphics graphics;
        int fps;
        std::vector<Entity *> entities;
};

#endif
