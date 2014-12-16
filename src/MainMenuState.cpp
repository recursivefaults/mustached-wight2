#include "MainMenuState.h"
#include "GameplayState.h"


MainMenuState::MainMenuState(GameStateManager *engine) : GameState(engine)
{
}
MainMenuState::~MainMenuState()
{
    SDL_Log("Main menu destroyed");
}
void MainMenuState::initialize()
{
    FontManager *fonts = engine->getFontManager();
    fonts->loadFontWithName("ostrich-bold.ttf", 64);
    fonts->loadFontWithName("ostrich-regular.ttf", 32);

    engine->getTextureManager()->loadTextureWithName("menu_background.png");
    SDL_Log("Main menu initialized");

    //Play music?
    //engine->getSoundEngine()->playMusic("Cinder.wav", 1);
}

void MainMenuState::pause()
{
    SDL_Log("Main menu paused");
}
void MainMenuState::resume()
{
    SDL_Log("Main menu resumed");
}
void MainMenuState::update(int elapsed)
{
}
void MainMenuState::handleInput()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) 
    {
        SDL_Log("Game exiting due to exit keys");
        //TODO: Fix this.
        engine->cleanUp();
    }
    if(e.type == SDL_KEYDOWN) {
        //We don't use a switch because mutiple keys are pressed
        SDL_Keycode c = e.key.keysym.sym;
        switch(c) {
           case SDLK_q:
                engine->cleanUp();
                break;
           case SDLK_RETURN:
                SDL_Log("Starting the game due to key press");
                //Start the game.
                engine->pushState(new GameplayState(engine));
                break;
        }
       
    }
}
void MainMenuState::render()
{
    Graphics *graphics = engine->getGraphics();
    graphics->clearRenderer();

    SDL_Rect loc = {0, 0, 800, 600};

    graphics->drawTexture(engine->getTextureManager()->getTextureForName("menu_background.png")->getTexture(), &loc);

    TTF_Font *boldFont = engine->getFontManager()->getFontWithName("ostrich-bold.ttf", 64);
    TTF_Font *font = engine->getFontManager()->getFontWithName("ostrich-regular.ttf", 32);

    int w = 0;
    int h = 0;
    TTF_SizeText(boldFont, "Walkers", &w, &h);
    loc = {800/2 - w/2, 40, w, h};
    renderFontAt(boldFont, loc, "Walkers");

    std::string instructions = "Press <Enter> to play, or 'q' to quit.";
    TTF_SizeText(font, instructions.c_str(), &w, &h);
    loc = {800/2 - w/2, 600/2 - h, w, h};
    renderFontAt(font, loc, instructions);

    instructions = "Press W,A,S,D to move. Space shoots.";
    TTF_SizeText(font, instructions.c_str(), &w, &h);
    loc = {5, 600 - h, w, h};
    renderFontAt(font, loc, instructions);

    instructions = "Hold Q on a corpse to loot it, E to burn it";
    TTF_SizeText(font, instructions.c_str(), &w, &h);
    loc = {800 - w - 5, 600 - h, w, h};
    renderFontAt(font, loc, instructions);

    graphics->render();
}

void MainMenuState::renderFontAt(TTF_Font *font, SDL_Rect &location, const std::string &text)
{
    Graphics *graphics = engine->getGraphics();
    SDL_Color color = {255, 255, 255};
    if(!font) 
    { 
        SDL_Log("Font didn't load %s", TTF_GetError());
    }
    graphics->renderFont(font, text, color, &location);
}
