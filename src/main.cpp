#include "walkers.h"
#include "Game.h"

int main()
{
    SDL_Log("Walkers initializing");
    Game g = Game();
    g.start();
    return 0;
}
