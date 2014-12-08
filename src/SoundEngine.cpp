#include "SoundEngine.h"

SoundEngine::SoundEngine()
{
    sounds = new SoundManager();
}

void SoundEngine::init() {
    int flags = Mix_Init(MIX_INIT_MP3);
    SDL_assert(MIX_INIT_MP3 == flags);
    SDL_assert(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == 0);

    SDL_Log("Sound engine loaded");
    setMusicVolumePercent(100.0f);
    SDL_Log("Music volume initialized to %d", Mix_VolumeMusic(-1));
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

void SoundEngine::playMusic(const std::string &name, int loops) const
{
    if(Mix_PlayingMusic()) {
        SDL_Log("Halting previous music playing");
        Mix_HaltMusic();
    }
    Mix_Music *sound = sounds->getMusicWithName(name);
    SDL_assert(sound != nullptr);
    int playing = Mix_PlayMusic(sound, loops);
    SDL_Log("Playing %s music", name.c_str());
    SDL_Log("Can't play music: %s", Mix_GetError());
    if(playing == -1) 
    {
        SDL_Log("Can't play music: %s", Mix_GetError());
    }
}

void SoundEngine::playMusicWithFade(const std::string &name, int fade, int loops) const
{
    Mix_Music *sound = sounds->getMusicWithName(name);
    SDL_assert(sound != nullptr);
    Mix_FadeInMusic(sound, loops, fade);
    SDL_Log("Playing %s music with fade", name.c_str());
}
