#include <chrono>
#include "GameStateManager.h"


GameStateManager::GameStateManager(Graphics *g, SoundEngine *s, TextureManager *t, FontManager *f) : _graphics(g), _sound(s), _textures(t), _fonts(f), running(true) 
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    _randomGenerator = new std::default_random_engine(seed);
};

GameStateManager::~GameStateManager()
{
    delete(_randomGenerator);
    while(!stateStack.empty())
    {
        delete(stateStack.top());
        stateStack.pop();
    }
    
}

void GameStateManager::cleanUp()
{
    running = false;
}

void GameStateManager::changeState(GameState *newState)
{
    if(!stateStack.empty())
    {
        delete(stateStack.top());
        stateStack.pop();
    }
    newState->initialize();
    stateStack.push(newState);
}

void GameStateManager::pushState(GameState *newState)
{
    if(!stateStack.empty())
    {
        stateStack.top()->pause();
        stateStack.push(newState);
    }
    newState->initialize();
    
}
void GameStateManager::popState()
{
    if(stateStack.empty())
    {
        return;
    }

    //Get rid of the current state
    delete(stateStack.top());
    stateStack.pop();

    stateStack.top()->resume();
}

void GameStateManager::handleInput()
{
    if(stateStack.empty()) {return;}
    stateStack.top()->handleInput();
}

void GameStateManager::update(int elapsed)
{
    if(stateStack.empty()) {return;}
    stateStack.top()->update(elapsed);
}

void GameStateManager::render()
{
    if(stateStack.empty()) {return;}
    stateStack.top()->render();
}
