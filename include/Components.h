#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "walkers.h"

enum class ComponentTypes
{
    POSITION,
    MOVEMENT,
    RENDERRECT
};

class Component
{
    public:
        Component() {};
        virtual ~Component() {};
};

struct Position : public Component
{
    public:
        int x, y;
};

struct Movement : public Component
{
    public:
        float dx, dy;
};

struct RenderRect : public Component
{
    public:
        SDL_Rect rect;
        int r, g, b, a;
};


#endif
