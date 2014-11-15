#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Graphics.h"
#include "Entity.h"
#include "World.h"
#include "System.h"

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
        void renderHud();
        void cleanUp();

        //TODO: I Don't like this
        bool continueRunning;

        int fps;
        Graphics graphics;
        World world;
        std::vector<System *> systems;
};

#endif
