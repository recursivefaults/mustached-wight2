#include "graphics.h"
#include <iostream> 


Graphics::Graphics() {
}

void Graphics::init()
{
    window = SDL_CreateWindow("Walkers", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Log("Graphics system initialized");
}

Graphics::~Graphics() {
    SDL_Log("Destroying graphics and windows");
    if(renderer != nullptr)
        SDL_DestroyRenderer(renderer);
    if(window != nullptr)
        SDL_DestroyWindow(window);
}

void Graphics::drawTexture(SDL_Texture *texture,
            const SDL_Rect *destination,
            const SDL_Rect *sourceRect) {
    SDL_RenderCopy(renderer, texture, sourceRect, destination);
}

void Graphics::drawRect(const SDL_Rect *rect, const SDL_Color &color, bool fill)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 1);
    if(fill)
    {
        SDL_RenderFillRect(renderer, rect);
    } else
    {
        if(SDL_RenderDrawRect(renderer, rect) != 0)
        {
            std::cout << "DrawRect Failed: " << SDL_GetError() << std::endl;
        }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
}

void Graphics::renderFont(TTF_Font *font, const std::string &text, const SDL_Color &color, const SDL_Rect *rect)
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surface);

    drawTexture(tex, rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(tex);
}
