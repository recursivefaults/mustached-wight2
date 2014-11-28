#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include <map>
#include <string>
#include "walkers.h"


class FontManager
{
    public:
        FontManager();
        ~FontManager();
        void loadFontWithName(const std::string &, const int);
        TTF_Font *getFontWithName(const std::string &, const int);
    protected:
    private:
        std::string getRealName(const std::string &, const int);
        std::map<std::string, TTF_Font *> fonts;
};

#endif
