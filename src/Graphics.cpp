#include "graphics.h"

#include <iostream>

Graphics::Graphics() {
    window = SDL_CreateWindow("Walkers", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Graphics::~Graphics() {
    if(renderer == nullptr)
        SDL_DestroyRenderer(renderer);
    if(window == nullptr)
        SDL_DestroyWindow(window);
}

void Graphics::drawTexture(SDL_Texture *texture,
            const SDL_Rect *destination,
            const SDL_Rect *sourceRect) {
    SDL_RenderCopy(renderer, texture, sourceRect, destination);
}

void Graphics::drawRect(const SDL_Rect *rect, int r, int g, int b, bool fill)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 1);
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
