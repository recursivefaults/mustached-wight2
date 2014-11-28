#include "GameStateManager.h"

GameStateManager::~GameStateManager()
{
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
