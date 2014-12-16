#ifndef ROOM_FACTORY_H
#define ROOM_FACTORY_H

#include <random>
#include "TextureManager.h"
#include "Room.h"

class RoomFactory
{
    public:
        RoomFactory(TextureManager *_textureManager) : textureManager(_textureManager) {};
        Room *generateRoom(bool, bool, bool, bool) const;
    protected:
        SDL_Rect getGrassyTile() const;
        SDL_Rect getNorthWallTile() const;
        SDL_Rect getSouthWallTile() const;
        SDL_Rect getEastWallTile() const;
        SDL_Rect getWestWallTile() const;
    private:
        TextureManager *textureManager;
        std::default_random_engine generator;
};

#endif
