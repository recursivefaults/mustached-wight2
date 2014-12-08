#ifndef SOUND_ENGINE_H
#define SOUND_ENGINE_H

#include "walkers.h"
#include "SoundManager.h"

class SoundEngine
{
    public:
        SoundEngine();
        ~SoundEngine();
        void init();
        void playSound(const std::string &, int) const;
        void playMusic(const std::string &, int) const;
        /**
         * Name
         * Fade in MS
         * Loops -1 forever
         **/
        void playMusicWithFade(const std::string &, int, int) const;
        void setMusicVolumePercent(const float percentage) {Mix_VolumeMusic(MIX_MAX_VOLUME * percentage);};
    protected:
    private:
        SoundManager *sounds;
};

#endif
