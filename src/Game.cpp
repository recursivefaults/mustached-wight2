#include "walkers.h"
#include "Game.h"
#include "Components.h"

Game::Game()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL failed to initizlize, how do we have this message?");
    }

    graphics = Graphics();
    world = World();

    fps = 60;

    Entity *e = new Entity();
    Position *p = new Position();
    p->x = 10;
    p->y = 10;
    Movement *m = new Movement();
    m->dx = 0.0f;
    m->dy = 0.0f;

    e->addComponent(ComponentTypes::POSITION, p); 
    e->addComponent(ComponentTypes::MOVEMENT, m); 
    world.addEntity(e);
    continueRunning = true;
    SDL_Log("Game initialized");
}

Game::~Game()
{
    SDL_Quit();
}
void Game::start()
{
    int msPerFrame = 1000/fps;
    const float kVelocity = 0.27;

    long previousFrameMs = SDL_GetTicks();

    while(continueRunning)
    {
        int current = SDL_GetTicks();
        const long elapsed = current - previousFrameMs;
        handleInput();
        //update
        
        //render
        render();
        
        if(elapsed < msPerFrame)
        {
            SDL_Delay(msPerFrame - elapsed);
        }
        previousFrameMs = current;

    }

}

void Game::update(int elapsedMs)
{
}

void Game::render()
{
    SDL_Rect rect;
    graphics.clearRenderer();

    //TODO: Make this real.
    rect.x = 10;
    rect.y = 10;
    rect.w = 16;
    rect.h = 16;

    graphics.drawRect(&rect, 10, 10, 200, true);
    graphics.render();
}

void Game::handleInput()
{

    SDL_Event e;
    world.clearKeys();
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) 
    {
        SDL_Log("Game exiting due to exit keys");
        continueRunning = false;
    }
    if(e.type == SDL_KEYDOWN) {
        //We don't use a switch because mutiple keys are pressed
        SDL_Keycode c = e.key.keysym.sym;
        if(c == SDLK_w) { world.pressKey(SDLK_w); }
        if(c == SDLK_a) { world.pressKey(SDLK_a); }
        if(c == SDLK_s) { world.pressKey(SDLK_s); }
        if(c == SDLK_d) { world.pressKey(SDLK_d); }
    }

}
