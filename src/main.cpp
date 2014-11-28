#include "walkers.h"
#include "MainMenuState.h"

int main()
{
    SDL_Log("SDL Initializing");
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL failed to initizlize, how do we have this message?");
    }

    //Initialize SDL_ttf


    Graphics graphics;
    SoundEngine soundEngine;

    graphics.init();
    soundEngine.init();

    TextureManager textureManager(graphics);
    FontManager fontManager;
    GameStateManager manager(&graphics, &soundEngine, &textureManager, &fontManager);
    manager.changeState(new MainMenuState(&manager));

    int fps = 60;
    int msPerFrame = 1000/fps;

    long previousFrameMs = SDL_GetTicks();

    SDL_Log("Beginning main game loop");
    
    while(manager.isRunning())
    {
        int current = SDL_GetTicks();
        const int elapsed = current - previousFrameMs;

        manager.handleInput();
        manager.update(elapsed);
        manager.render();

        if(elapsed < msPerFrame)
        {
            //Rest to keep 60 fps
            SDL_Delay(msPerFrame - elapsed);
        }
        previousFrameMs = current;
    }
    manager.cleanUp();
    SDL_Quit();
    return 0;
}
