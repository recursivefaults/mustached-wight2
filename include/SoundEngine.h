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
    protected:
    private:
        SoundManager *sounds;
};

#endif
