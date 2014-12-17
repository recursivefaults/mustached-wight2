#ifndef ROOM_FACTORY_H
#define ROOM_FACTORY_H

#include <random>
#include "TextureManager.h"
#include "Room.h"

class RoomFactory
{
    public:
        RoomFactory(TextureManager *_textureManager);
        Room *generateRoom(bool, bool, bool, bool);
    protected:
        SDL_Rect getGrassyTile();
        SDL_Rect getNorthWallTile();
        SDL_Rect getSouthWallTile();
        SDL_Rect getEastWallTile();
        SDL_Rect getWestWallTile();
    private:
        TextureManager *textureManager;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> grassyDistribution;
};

#endif
