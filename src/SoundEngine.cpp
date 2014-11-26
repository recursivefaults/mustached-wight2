#include "SoundEngine.h"

SoundEngine::SoundEngine()
{
    sounds = new SoundManager();
}

void SoundEngine::init() {
    SDL_assert(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == 0);
    SDL_Log("Sound engine loaded");
}

SoundEngine::~SoundEngine()
{
    delete(sounds);
    Mix_CloseAudio();
}

void SoundEngine::playSound(const std::string &name, int loops) const
{
    SDL_Log("Playing %s sound", name.c_str());
    Mix_Chunk *sound = sounds->getSoundWithName(name);
    SDL_assert(sound != nullptr);
    Mix_PlayChannel(-1, sound, loops);
}
