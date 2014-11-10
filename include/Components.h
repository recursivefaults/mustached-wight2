#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "walkers.h"

enum class ComponentTypes
{
    POSITION,
    VELOCITY,
    RENDERRECT,
    LIFE,
    FACING,
    EASTFACING,
    WESTFACING,
    NORTHFACING,
    SOUTHFACING,
    PLAYERINPUT,
    CANSHOOT,
    BULLET,
    MONSTER,
    REMOVE,
    COLLIDABLE

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

struct Velocity : public Component
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

struct Facing : public Component {};

struct NorthFacing : public Component {};
struct SouthFacing : public Component {};
struct WestFacing : public Component {};
struct EastFacing : public Component {};

struct Bullet : public Component {};

struct CanShoot : public Component 
{
    public:
        const int  msBetweenShots = 400;
        int currentMs;
};

struct PlayerInput : public Component {};

struct Monster : public Component {};

struct Life : public Component {
    public:
        Life(int _hp) : hp(_hp), damage(0) {}; 
        int hp;
        int damage;
};

struct Remove : public Component {};

struct Collidable : public Component {};


#endif
