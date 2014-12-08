#include "SoundManager.h"
#include "asset_helper.h"

SoundManager::~SoundManager()
{
    for(auto kv : musicMap)
    {
        Mix_FreeMusic(kv.second);
        SDL_Log("Music %s has been cleaned up", kv.first.c_str());
    }
    for(auto kv : soundMap)
    {
        Mix_FreeChunk(kv.second);
        SDL_Log("Sound %s has been cleaned up", kv.first.c_str());
    }
}
void SoundManager::loadSoundWithName(const std::string &soundName)
{
    AssetHelper helper;
    Mix_Chunk *chunk = Mix_LoadWAV(helper.fullAssetPathForFile(soundName).c_str());
    soundMap.insert(std::pair<std::string, Mix_Chunk *>(soundName, chunk));
    SDL_Log("Sound %s loaded.", soundName.c_str());
}

Mix_Chunk *SoundManager::getSoundWithName(const std::string &name)
{
    std::map<std::string, Mix_Chunk *>::iterator finder = soundMap.find(name);
    if(finder == soundMap.end())
    {
        SDL_Log("Sound %s not loaded, loading it now", name.c_str());
        loadSoundWithName(name);
    }
    return soundMap.at(name);
}

void SoundManager::loadMusicWithName(const std::string &name)
{
    AssetHelper helper;
    Mix_Music *chunk = Mix_LoadMUS(helper.fullAssetPathForFile(name).c_str());
    if(!chunk) 
    {
        SDL_Log("Music didn't load: %s", Mix_GetError());
    }
    SDL_assert(chunk != nullptr);
    musicMap.insert(std::pair<std::string, Mix_Music *>(name, chunk));
    SDL_Log("Music %s loaded.", name.c_str());
}

Mix_Music *SoundManager::getMusicWithName(const std::string &name)
{
    std::map<std::string, Mix_Music *>::iterator finder = musicMap.find(name);
    if(finder == musicMap.end())
    {
        SDL_Log("Music %s not loaded, loading it now", name.c_str());
        loadMusicWithName(name);
    }
    return musicMap.at(name);
}
