#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GameState.h"
#include "Graphics.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "SoundEngine.h"
#include "Entity.h"
#include "World.h"
#include "System.h"

class GameplayState : public GameState
{
    public:
        GameplayState(GameStateManager *_engine);
        ~GameplayState();
        void initialize() {};
        void pause() {};
        void resume() {};
        void handleInput();
        void update(int elapsedMs);
        void render();
    protected:
    private:
        void renderHud();
        void cleanUp();

        World world;
        std::vector<System::System *> systems;
};

#endif
