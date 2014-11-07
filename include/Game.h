#ifndef GAME_H
#define GAME_H

#include "Graphics.h"
#include "Entity.h"
#include "World.h"

class Game
{
    public:
        Game();
        ~Game();
        void start();
    protected:
    private:
        void handleInput();
        void update(int elapsedMs);
        void render();

        //TODO: I Don't like this
        bool continueRunning;

        int fps;
        Graphics graphics;
        World world;
};

#endif
