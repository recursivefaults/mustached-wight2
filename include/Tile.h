#ifndef TILE_H
#define TILE_H

#include "Texture.h"

enum class TileType
{
    NORMAL,
    COLLIDABLE,
    NORTH_EXIT,
    SOUTH_EXIT,
    EAST_EXIT,
    WEST_EXIT
};

class Tile
{
    public:
        Tile(SDL_Rect, Texture *, TileType);
        ~Tile();
        SDL_Rect getOriginRect() const { return originRect; };
        TileType getFlag() const { return flag; };
        Texture *getTexture() const { return texture; };
    protected:
    private:
        SDL_Rect originRect;
        Texture *texture;
        TileType flag;

};

#endif
