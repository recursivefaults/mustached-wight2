#include "Map.h"

Map::Map()
{
    currentRoom = nullptr;
}
Map::~Map()
{
    for(auto room : rooms)
    {
        delete(room);
    }
    currentRoom = nullptr;
}
void Map::addRoom(Room *room)
{
    rooms.push_back(room);
}
