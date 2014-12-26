#include <string>

#include "walkers.h"
#include "GameplayState.h"
#include "Components.h"
#include "SystemFactory.h"
#include "asset_helper.h"
#include "EntityFactory.h"
#include "GameOverState.h"
#include "RoomFactory.h"
#include "Room.h"

GameplayState::GameplayState(GameStateManager *engine) : GameState(engine)
{
    TextureManager *textureManager = engine->getTextureManager();
    textureManager->loadTextureWithName("Hero.png");
    textureManager->loadTextureWithName("Zombie.png");
    textureManager->loadTextureWithName("Corpse.png");
    textureManager->loadTextureWithName("forest2.png");
    textureManager->loadTextureWithName("zelda-like.png");

    RoomFactory rf(textureManager);
    currentMap = new Map();
    Room *r = rf.generateRoom(false, false, false, false);
    currentMap->addRoom(r);
    currentMap->setCurrentRoom(r);

    engine->getFontManager()->loadFontWithName("ostrich-regular.ttf", 24);


    System::SystemFactory f;
    systems = f.constructSystems(engine);
    SDL_Log("Systems constructed");

    EntityFactory entityFactory = EntityFactory();
    World *world = currentMap->getCurrentRoom()->getWorld();

    world->addEntity(entityFactory.createPlayer());
    world->addEntity(entityFactory.createSpawnCounter());

    //TODO:: Move this to a spawn thingie
    Position *p = new Position();
    p->x = 740;
    p->y = 10;
    world->addEntity(entityFactory.createZombie(p));


    SDL_Log("Gameplay initialized");
}

GameplayState::~GameplayState()
{
    delete(currentMap);
    SDL_Log("Destroying gameplay");
    systems.clear();
    //TODO: Delete all systems
}

void GameplayState::initialize()
{
    //Start the music!
    //engine->getSoundEngine()->playMusicWithFade("Cinder.wav", 300, -1);
}

void GameplayState::cleanUp()
{

    SDL_Log("Cleaning up resources and quitting");
    SDL_Quit();
}

void GameplayState::update(int elapsedMs)
{
    World *world = currentMap->getCurrentRoom()->getWorld();
    for(auto system : systems)
    {
        system->update(elapsedMs, *world);
    }
    if(world->getGameOver())
    {
        engine->changeState(new GameOverState(engine));
    }
}

void GameplayState::render()
{
    SDL_Rect rect;
    Graphics *graphics = engine->getGraphics();
    graphics->clearRenderer();
    World *world = currentMap->getCurrentRoom()->getWorld();

    renderMap();

    /**
     * Render the HUD
     * Render the game
     */

    for(auto entity : world->getEntitiesForType(ComponentTypes::RENDERRECT))
    {
        RenderRect *r = (RenderRect *) entity->getComponent(ComponentTypes::RENDERRECT);
        Position *p = (Position *) entity->getComponent(ComponentTypes::POSITION);
        rect.x = p->x;
        rect.y = p->y;
        rect.h = r->rect.h;
        rect.w = r->rect.w;
        if(r->spriteName.length() == 0)
        {
            graphics->drawRect(&rect, r->color, true);
        }
        else if(r->textureRect.w == 0)
        {
            graphics->drawTexture(engine->getTextureManager()->getTextureForName(r->spriteName)->getTexture(), &rect);
        }
        else
        {
            graphics->drawTexture(engine->getTextureManager()->getTextureForName(r->spriteName)->getTexture(), &rect, &r->textureRect);
        }
    }

    renderHud();
    graphics->render();
}

void GameplayState::renderMap()
{
    Room *room = currentMap->getCurrentRoom();
    Graphics *graphics = engine->getGraphics();
    //Render the background
    Tile *tile = nullptr;
    SDL_Rect destination, origin;
    for(int i = 0; i < room->getHeight(); ++i)
    {
        for(int j = 0; j < room->getWidth(); ++j)
        {
            destination = { j * 16, i * 16, 16, 16 }; 
            tile = room->getTileAt(j, i);
            origin = tile->getOriginRect();
            graphics->drawTexture(tile->getTexture()->getTexture(), &destination, &origin); 
        }
    }
}

void GameplayState::renderHud()
{

    World *world = currentMap->getCurrentRoom()->getWorld();
    Graphics *graphics = engine->getGraphics();
    TTF_Font *font = engine->getFontManager()->getFontWithName("ostrich-regular.ttf", 24);
    SDL_Color color = {255, 255, 255};
    Entity *player = world->getEntitiesForType(ComponentTypes::AMMO).front();
    Ammo *ammo = (Ammo *) player->getComponent(ComponentTypes::AMMO);
    Life *life = (Life *) player->getComponent(ComponentTypes::LIFE);

    std::string lifeString = "Life: " + std::to_string(life->hp - life->damage);
    std::string ammoString = "Ammo: " + std::to_string(ammo->ammo);

    int w = 0;
    int h = 0;
    TTF_SizeText(font, lifeString.c_str(), &w, &h);

    SDL_Rect loc = {5, 5, w, h};
    graphics->renderFont(font, lifeString, color, &loc);

    TTF_SizeText(font, ammoString.c_str(), &w, &h);

    loc = {5, 25, w, h};
    graphics->renderFont(font, ammoString, color, &loc);


    //Render the countdown
    Entity *corpseCounter = world->getEntitiesForType(ComponentTypes::CORPSE_COUNTER).front();
    CorpseCounter *counter = (CorpseCounter *) corpseCounter->getComponent(ComponentTypes::CORPSE_COUNTER);
    SDL_assert(counter->totalMsNeeded - counter->elapsedMs > 0);
    int delta = counter->totalMsNeeded - counter->elapsedMs;
    int minutes = delta/(1000 * 60);
    int seconds = delta/(1000);
    int ms = delta % 1000;
    char time[10];

    std::sprintf(time, "%02d:%02d:%03d", minutes, seconds, ms);
    std::string spawnString = "Next Spawn: " + std::string(time);

    TTF_SizeText(font, spawnString.c_str(), &w, &h);
    loc = {800 - 155, 5, w, h};
    graphics->renderFont(font, spawnString.c_str(), color, &loc);
}


void GameplayState::handleInput()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    World *world = currentMap->getCurrentRoom()->getWorld();
    if (e.type == SDL_QUIT) 
    {
        SDL_Log("Game exiting due to exit keys");
        //TODO: Fix this.
        engine->cleanUp();
    }
    if(e.type == SDL_KEYDOWN) {
        //We don't use a switch because mutiple keys are pressed
        SDL_Keycode c = e.key.keysym.sym;
        world->pressKey(c);
    }
    if(e.type == SDL_KEYUP) {
        //We don't use a switch because mutiple keys are pressed
        SDL_Keycode c = e.key.keysym.sym;
        world->unPressKey(c);
    }
}
