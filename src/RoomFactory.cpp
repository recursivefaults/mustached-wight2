#include "RoomFactory.h"
#include "Tile.h"

RoomFactory::RoomFactory(TextureManager *_textureManager) : textureManager(_textureManager)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator = std::default_random_engine(seed);
    grassyDistribution = std::uniform_int_distribution<int>(1, 2);
}

Room *RoomFactory::generateRoom(bool northExit, bool southExit, bool eastExit, bool westExit)
{
    Room *theRoom = new Room(800/16, 600/16);
    Texture *texture = textureManager->getTextureForName("zelda-like.png");
    int widthMax = 800/16;
    int heightMax = 600/16;
    for(int i = 0; i < heightMax; ++i)
    {
        for(int j = 0; j < widthMax; ++j)
        {
            /**
             * Deal with the borders
             */
            Tile *t = new Tile(getGrassyTile(), texture, TileType::NORMAL);
            theRoom->setTileAt(t, j, i);
        }
    }

    /**
     * Do the borders
     */
    if(northExit)
    {
        delete(theRoom->getTileAt(widthMax/2, 0));
        delete(theRoom->getTileAt(widthMax/2 - 1, 0));
        Tile *one = new Tile(getGrassyTile(), texture, TileType::NORTH_EXIT);
        theRoom->setTileAt(one, widthMax/2, 0);
        one = new Tile(getGrassyTile(), texture, TileType::NORTH_EXIT);
        theRoom->setTileAt(one, widthMax/2 - 1, 0);
    }
    if(southExit)
    {
        delete(theRoom->getTileAt(widthMax/2, heightMax));
        delete(theRoom->getTileAt(widthMax/2 - 1, heightMax));
        Tile *one = new Tile(getGrassyTile(), texture, TileType::SOUTH_EXIT);
        theRoom->setTileAt(one, widthMax/2, heightMax);
        one = new Tile(getGrassyTile(), texture, TileType::SOUTH_EXIT);
        theRoom->setTileAt(one, widthMax/2 - 1, heightMax);
    }
    if(eastExit)
    {
        delete(theRoom->getTileAt(widthMax, heightMax/2));
        delete(theRoom->getTileAt(widthMax, heightMax/2 - 1));
        Tile *one = new Tile(getGrassyTile(), texture, TileType::EAST_EXIT);
        theRoom->setTileAt(one, widthMax, heightMax/2);
        one = new Tile(getGrassyTile(), texture, TileType::EAST_EXIT);
        theRoom->setTileAt(one, widthMax, heightMax/2 - 1);
    }
    if(westExit)
    {
        delete(theRoom->getTileAt(0, heightMax/2));
        delete(theRoom->getTileAt(0, heightMax/2 - 1));
        Tile *one = new Tile(getGrassyTile(), texture, TileType::WEST_EXIT);
        theRoom->setTileAt(one, 0, heightMax/2);
        one = new Tile(getGrassyTile(), texture, TileType::WEST_EXIT);
        theRoom->setTileAt(one, 0, heightMax/2 - 1);
    }
    return theRoom;
}

SDL_Rect RoomFactory::getGrassyTile()
{
    int roomType = grassyDistribution(generator);
    if(roomType == 1)
        return {6 * 16, 5 * 16, 16, 16};
    if(roomType == 2)
        return {5 * 16, 5 * 16, 16, 16};
}
SDL_Rect RoomFactory::getNorthWallTile()
{
    return {128/16 - 2, 208/16/2, 16, 16};
}
SDL_Rect RoomFactory::getSouthWallTile()
{
    return {128/16 - 2, 208/16/2, 16, 16};
}
SDL_Rect RoomFactory::getEastWallTile()
{
    return {128/16 - 2, 208/16/2, 16, 16};
}
SDL_Rect RoomFactory::getWestWallTile()
{
    return {128/16 - 2, 208/16/2, 16, 16};
}

