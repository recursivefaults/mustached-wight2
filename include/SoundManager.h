#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <map>
#include <string>
#include "walkers.h"

class SoundManager
{
    public:
        SoundManager() {};
        ~SoundManager();
        void loadSoundWithName(const std::string &);
        Mix_Chunk *getSoundWithName(const std::string &);
        void loadMusicWithName(const std::string &);
        Mix_Music *getMusicWithName(const std::string &);
    protected:
    private:
        std::map<std::string, Mix_Chunk *> soundMap;
        std::map<std::string, Mix_Music *> musicMap;
};


#endif
