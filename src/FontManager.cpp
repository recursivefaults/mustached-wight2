#include "FontManager.h"
#include "asset_helper.h"

FontManager::FontManager()
{
    //TODO: Font rendering class?
    TTF_Init();
}
FontManager::~FontManager()
{
    for(auto kv : fonts)
    {
        SDL_Log("Releasing font %s", kv.first.c_str());
        TTF_CloseFont(kv.second);
    }
    //TODO: Move the ttf out.
    TTF_Quit();

}
void FontManager::loadFontWithName(const std::string &fontName, const int pointSize)
{
    AssetHelper helper;
    TTF_Font *font = nullptr;
    font = TTF_OpenFont(helper.fullAssetPathForFile(fontName).c_str(), pointSize);
    SDL_assert(font != nullptr);
    SDL_Log("Loaded font %s", fontName.c_str());
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
