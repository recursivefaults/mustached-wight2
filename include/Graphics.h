#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "walkers.h"
#include <SDL2/SDL_ttf.h>
#include <string>

class Graphics {
    public:
    Graphics();
    ~Graphics();
    void init();
    void drawTexture(SDL_Texture *texture,
            const SDL_Rect *destination,
            const SDL_Rect *sourceRect = nullptr);
    void drawRect(const SDL_Rect *rect, const SDL_Color &color, bool fill=false);
    void renderFont(TTF_Font *, const std::string &, const SDL_Color &, const SDL_Rect *);
    void clearRenderer() { SDL_RenderClear(renderer); };
    void render() { SDL_RenderPresent(renderer);};
    SDL_Renderer *getRenderer() { return renderer;}

    private:
    SDL_Renderer *renderer;
    SDL_Window *window;
};

#endif
