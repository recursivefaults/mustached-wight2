#include "asset_helper.h"
#include <iostream>


SDL_Texture *AssetHelper::loadNamedTexture(const std::string &fileName, Graphics &graphics) {

    SDL_Texture *texture = IMG_LoadTexture(graphics.getRenderer(), fullAssetPathForFile(fileName).c_str());
    SDL_assert(texture != nullptr);
    SDL_Log("Loaded texture %s", fileName.c_str());
    return texture;
}
std::string AssetHelper:: fullAssetPathForFile(const std::string &fileName) {
    std::string full_path = std::string(SDL_GetBasePath()); 
    full_path += "assets/" + fileName;
    return full_path;
}
