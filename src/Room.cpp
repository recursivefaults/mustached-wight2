#include "Room.h"
#include "walkers.h"

Room::Room(const int _width, const int _height) : width(_width), height(_height)
{
    north = nullptr;
    west = nullptr;
    east = nullptr;
    south = nullptr;
    mapData.resize(height);
    for(int i = 0; i < _height; ++i)
    {
        mapData[i].resize(_width);
    }
}

Room::~Room()
{
    SDL_Log("Room deleted");
}

void Room::setTileAt(Tile *tile, const int x, const int y)
{
    mapData[y][x] = tile;
}

Tile *Room::getTileAtPoint(const int px, const int py) const
{
    SDL_assert(px <= 800 && px >= 0);
    SDL_assert(py <= 600 && py >= 0);
    int tileX = px/16;
    int tileY = py/16;
    
    return mapData[tileY][tileX];
}
Tile *Room::getTileAt(const int px, const int py) const
{
    SDL_assert(py < mapData.size());
    SDL_assert(px < mapData[0].size());
    return mapData[py][px];
}
