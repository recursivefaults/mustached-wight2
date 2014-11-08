#include "walkers.h"
#include "Game.h"
#include "Components.h"
#include "SystemFactory.h"

#include "EntityFactory.h"

Game::Game()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL failed to initizlize, how do we have this message?");
    }

    graphics = Graphics();
    world = World();

    SystemFactory f = SystemFactory();
    systems = f.constructSystems();

    SDL_Log("Systems constructed");

    fps = 60;

    EntityFactory entityFactory = EntityFactory();

    world.addEntity(entityFactory.createPlayer());

    //TODO:: Move this to a spawn thingie
    Position *p = new Position();
    p->x = 740;
    p->y = 10;
    world.addEntity(entityFactory.createZombie(p));

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

        //gather input
        handleInput();

        //update
        update(elapsed);
        
        //render
        render();
        
        if(elapsed < msPerFrame)
        {
            //Rest to keep 60 fps
            SDL_Delay(msPerFrame - elapsed);
        }
        previousFrameMs = current;

    }
    cleanUp();

}

void Game::cleanUp()
{
    SDL_Log("Cleaning up resources and quitting");
    SDL_Quit();
}

void Game::update(int elapsedMs)
{
    for(auto system : systems)
    {
        system->update(elapsedMs, world);
    }
}

void Game::render()
{
    SDL_Rect rect;
    graphics.clearRenderer();

    for(auto entity : world.getEntitiesForType(ComponentTypes::RENDERRECT))
    {
        RenderRect *r = (RenderRect *) entity->getComponent(ComponentTypes::RENDERRECT);
        Position *p = (Position *) entity->getComponent(ComponentTypes::POSITION);
        rect.x = p->x;
        rect.y = p->y;
        rect.h = r->rect.h;
        rect.w = r->rect.w;
        graphics.drawRect(&rect, r->r, r->g, r->b, true);
    }
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
        world.pressKey(c);
    }
}
