#include "GameOverState.h"
#include "GameplayState.h"

GameOverState::GameOverState(GameStateManager *engine) : GameState(engine)
{
}
GameOverState::~GameOverState()
{
}
void GameOverState::initialize()
{
    FontManager *fonts = engine->getFontManager();
    fonts->loadFontWithName("ostrich-bold.ttf", 64);
    fonts->loadFontWithName("ostrich-regular.ttf", 32);
    SDL_Log("Game over screen initialize");

}
void GameOverState::pause()
{
}
void GameOverState::resume()
{
}
void GameOverState::update(int elapsed)
{
}
void GameOverState::handleInput()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) 
    {
        SDL_Log("Game exiting due to exit keys");
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
                engine->changeState(new GameplayState(engine));
                break;
        }
    }
}
void GameOverState::render()
{
    Graphics *graphics = engine->getGraphics();
    FontManager *fontManager = engine->getFontManager();
    SDL_Color color = {255, 255, 255};
    SDL_Rect location = {0, 0, 0, 0};
    int w, h = 0;

    graphics->clearRenderer();

    TTF_Font *boldFont = fontManager->getFontWithName("ostrich-bold.ttf", 64);
    TTF_Font *font = fontManager->getFontWithName("ostrich-regular.ttf", 32);

    std::string text = "You Died";
    TTF_SizeText(boldFont, text.c_str(), &w, &h);
    location = {800/2 - w/2, 600/3, w, h};
    graphics->renderFont(boldFont, text, color, &location);

    text = "Press Enter to play again, or Q to quit";
    TTF_SizeText(font, text.c_str(), &w, &h);
    location = {800/2 - w/2, 600/3 * 2, w, h};
    graphics->renderFont(font, text, color, &location);

    graphics->render();
    
}
