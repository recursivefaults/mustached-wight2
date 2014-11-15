#include <string>

#include "walkers.h"
#include "Game.h"
#include "Components.h"
#include "SystemFactory.h"

#include "asset_helper.h"

#include "EntityFactory.h"

Game::Game()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL failed to initizlize, how do we have this message?");
    }

    graphics = Graphics();
    world = World();

    //Initialize SDL_ttf
    //TODO: Font rendering class?
    TTF_Init();

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

        //Render HUD
        
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

    /**
     * Render the HUD
     * Render the game
     */

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

    renderHud();
    graphics.render();
}

void Game::renderHud()
{
    SDL_Texture *ammoText, *lifeText;
    AssetHelper helper;
    TTF_Font *font = TTF_OpenFont(helper.fullAssetPathForFile("ostrich-black.ttf").c_str(), 24);
    SDL_Color color = {255, 255, 255};
    if(!font) 
    { 
        SDL_Log("Font didn't load %s", TTF_GetError());
    }
    Entity *player = world.getEntitiesForType(ComponentTypes::AMMO).front();
    Ammo *ammo = (Ammo *) player->getComponent(ComponentTypes::AMMO);
    Life *life = (Life *) player->getComponent(ComponentTypes::LIFE);

    std::string lifeString = "Life: " + std::to_string(life->hp - life->damage);
    std::string ammoString = "Ammo: " + std::to_string(ammo->ammo);

    SDL_Surface *surface = TTF_RenderText_Solid(font, lifeString.c_str(), color);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(graphics.getRenderer(), surface);
    SDL_Rect loc = {5, 5, 20, 10};
    graphics.drawTexture(tex, &loc);
    surface = TTF_RenderText_Solid(font, ammoString.c_str(), color);
    tex = SDL_CreateTextureFromSurface(graphics.getRenderer(), surface);
    loc = {5, 25, 30, 10};
    graphics.drawTexture(tex, &loc);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(tex);
    
}


void Game::handleInput()
{

    SDL_Event e;
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
    if(e.type == SDL_KEYUP) {
        //We don't use a switch because mutiple keys are pressed
        SDL_Keycode c = e.key.keysym.sym;
        world.unPressKey(c);
    }
}
