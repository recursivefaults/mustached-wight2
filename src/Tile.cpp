#include "walkers.h"
#include "Tile.h"

Tile::Tile(SDL_Rect origin, Texture *_texture, TileType _flag) : originRect(origin), texture(_texture), flag(_flag)

{
}

Tile::~Tile()
{
    SDL_Log("Tile deleted!");
}

