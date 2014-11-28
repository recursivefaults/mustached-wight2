#include "FontManager.h"
#include "asset_helper.h"

FontManager::FontManager()
{
}
FontManager::~FontManager()
{
    for(auto kv : fonts)
    {
        SDL_Log("Releasing font %s", kv.first.c_str());
        TTF_CloseFont(kv.second);
    }
}
void FontManager::loadFontWithName(const std::string &fontName, const int pointSize)
{
    AssetHelper helper;
    TTF_Font *font = TTF_OpenFont(helper.fullAssetPathForFile(fontName).c_str(), pointSize);
    fonts.insert(std::pair<std::string, TTF_Font*>(getRealName(fontName, pointSize), font));
}

TTF_Font *FontManager::getFontWithName(const std::string &fontName, const int pointSize)
{
    std::string realName = getRealName(fontName, pointSize);
    std::map<std::string, TTF_Font *>::iterator finder = fonts.find(realName);
    if(finder == fonts.end())
    {
        SDL_Log("Couldn't load font: %s, loading now", fontName.c_str());
        loadFontWithName(fontName, pointSize);
    }
    return fonts.at(realName);
}

std::string FontManager::getRealName(const std::string &fontName, const int pointSize)
{
    std::string realName = fontName + std::to_string(pointSize);
    return realName;
}
