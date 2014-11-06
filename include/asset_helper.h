#ifndef ASSETHELPER_H
#define ASSETHELPER_H

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include "graphics.h"

class AssetHelper {
    public:
        /** 
         * Loads a SDL_Texture given a Graphics context.
         *
         * It does not maintain ownership of the pointer created.
         **/
        SDL_Texture *loadNamedTexture(const std::string &fileName, Graphics &graphics);
        std::string fullAssetPathForFile(const std::string &fileName);

    private:

};

#endif
