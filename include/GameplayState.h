#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GameState.h"
#include "System.h"
#include "Map.h"

class GameplayState : public GameState
{
    public:
        GameplayState(GameStateManager *_engine);
        ~GameplayState();
        void initialize();
        void pause() {};
        void resume() {};
        void handleInput();
        void update(int elapsedMs);
        void render();
    protected:
    private:
        void renderHud();
        void renderMap();
        void cleanUp();

        std::vector<System::System *> systems;
        Map *currentMap;
};

#endif
