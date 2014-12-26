#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "World.h"
#include "Tile.h"

class Room
{
    public:
        Room(const int _width, const int _height);
        ~Room();
        Tile *getTileAtPoint(const int px, const int py) const;
        Tile *getTileAt(const int px, const int py) const;
        void setTileAt(Tile *tile, const int x, const int y);
        int getWidth() const {return width;};
        int getHeight() const {return height;};
        void setWestRoom(Room *r) {west = r;};
        void setEastRoom(Room *r) {east = r;};
        void setNorthRoom(Room *r) {north = r;};
        void setSouthRoom(Room *r) {south = r;};
        Room *getNorthRoom() const {return north;};
        Room *getEastRoom() const {return east;};
        Room *getWestRoom() const {return west;};
        Room *getSouthRoom() const {return south;};
        World *getWorld() {return &world;};
    protected:
    private:
        Room *north;
        Room *south;
        Room *east;
        Room *west;
        World world;
        int width, height;
        std::vector< std::vector<Tile*> > mapData;
};

#endif
