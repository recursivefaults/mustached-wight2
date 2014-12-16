#include "RoomFactory.h"
#include "Tile.h"

Room *RoomFactory::generateRoom(bool northExit, bool southExit, bool eastExit, bool westExit) const
{
    Room *theRoom = new Room(800/16, 600/16);
    for(int i = 0; i < 600/16; ++i)
    {
        for(int j = 0; j < 800/16; ++j)
        {
            /**
             * Deal with the borders
             */
            Texture *texture = textureManager->getTextureForName("zelda-like.png");
            Tile *t = new Tile(getGrassyTile(), texture, TileType::NORMAL);
            theRoom->setTileAt(t, j, i);
        }
    }

    return theRoom;
}
SDL_Rect RoomFactory::getGrassyTile() const
{
    return {6 * 16, 5 * 16, 16, 16};
}
SDL_Rect RoomFactory::getNorthWallTile() const
{
    return {128/16 - 2, 208/16/2, 16, 16};
}
SDL_Rect RoomFactory::getSouthWallTile() const
{
    return {128/16 - 2, 208/16/2, 16, 16};
}
SDL_Rect RoomFactory::getEastWallTile() const
{
    return {128/16 - 2, 208/16/2, 16, 16};
}
SDL_Rect RoomFactory::getWestWallTile() const
{
    return {128/16 - 2, 208/16/2, 16, 16};
}

