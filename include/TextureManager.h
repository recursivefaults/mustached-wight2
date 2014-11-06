#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <map>


#include "Graphics.h"
#include "Texture.h"

class TextureManager
{
    public:
        TextureManager(Graphics &graphics) { _graphics = &graphics;};
        Texture *getTextureForName(const std::string &name);
        void loadTextureWithName(const std::string &name);
    private:
    protected:
        Graphics *_graphics;
        std::map<std::string, Texture *> _spriteIndex;
};

#endif
