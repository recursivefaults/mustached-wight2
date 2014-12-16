#ifndef ROOM_H
#define ROOM_H

#include <vector>
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
    protected:
    private:
        int width, height;
        std::vector< std::vector<Tile*> > mapData;
};

#endif
