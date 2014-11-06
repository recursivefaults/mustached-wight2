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
    entities.push_back(e);
    SDL_Log("Added player entitiy, now there are %d entities in the world.", entities.size());
}

Game::~Game()
{
    SDL_Quit();
}
void Game::start()
{
    int msPerFrame = 1000/fps;
    bool continueRunning = true;
    const float kVelocity = 0.27;

    long previousFrameMs = SDL_GetTicks();
    SDL_Event e;
    SDL_Rect rect;

    Entity *player = entities[0];
    if(player == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "There's no player, but there freaking ought to be");
    }

    while(continueRunning)
    {
        int current = SDL_GetTicks();
        const long elapsed = current - previousFrameMs;
        SDL_PollEvent(&e);
        handleInput(e);
        if (e.type == SDL_QUIT) 
        {
            SDL_Log("Game exiting due to exit keys");
            continueRunning = false;
        }
        if(e.type == SDL_KEYDOWN) {
            Position *p = (Position *)player->getComponent(ComponentTypes::POSITION);
            if(p == nullptr) {
                SDL_Log("Couldn't get component, skipping frame");
                break;
            }
            switch(e.key.keysym.sym)
            {
                case SDLK_w:
                    p->y += -kVelocity * elapsed;
                    if(p->y <= 0) { p->y = 0;}
                    break;
                case SDLK_a:
                    p->x += -kVelocity * elapsed;
                    if(p->x <= 0) { p->x = 0;}
                    break;
                case SDLK_s:
                    p->y += kVelocity * elapsed;
                    if(p->y >= 480) { p->y = 480-10;}
                    break;
                case SDLK_d:
                    p->x += kVelocity * elapsed;
                    if(p->x >= 600) { p->x = 600-10;}
                    break;
            }
        }
        Position *p = (Position *)player->getComponent(ComponentTypes::POSITION);
        graphics.clearRenderer();
        //update
        //render
        //TODO: Make this real.
        rect.x = p->x;
        rect.y = p->y;
        rect.w = 16;
        rect.h = 16;
        graphics.drawRect(&rect, 10, 10, 200, true);
        graphics.render();
        
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
}

void Game::handleInput(SDL_Event &e)
{
}
