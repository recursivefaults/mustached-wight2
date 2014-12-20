#include "Map.h"

Map::Map()
{
    currentRoom = nullptr;
}
Map::~Map()
{
}
void Map::addRoom(Room *room)
{
    rooms.push_back(room);
}
