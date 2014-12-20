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
    return nullptr;
}
Tile *Room::getTileAt(const int px, const int py) const
{
    return mapData[py][px];
}
