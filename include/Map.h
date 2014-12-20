#ifndef MAP_H
#define MAP_H

#include <list>
#include "Room.h"

class Map
{
    public:
        Map();
        ~Map();
        void addRoom(Room *);
        void setCurrentRoom(Room *r) { currentRoom = r; };
        Room *getCurrentRoom() {return currentRoom;}
    protected:
    private:
        Room *currentRoom;
        std::list<Room *> rooms;
};

#endif
