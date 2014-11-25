#include "SoundEngine.h"

SoundEngine::SoundEngine()
{
    SDL_assert(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == 0);
    SDL_Log("Sound engine loaded");
    sounds = new SoundManager();
}

SoundEngine::~SoundEngine()
{
    delete(sounds);
    Mix_CloseAudio();
}

void SoundEngine::playSound(const std::string &name, int loops)
{
    Mix_Chunk *sound = sounds->getSoundWithName(name);
    SDL_assert(sound != nullptr);
    Mix_PlayChannel(-1, sound, loops);
}
