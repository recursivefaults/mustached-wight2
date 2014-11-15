#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "walkers.h"

enum class ComponentTypes
{
    POSITION,
    VELOCITY,
    RENDERRECT,
    LIFE,
    AMMO,
    FACING,
    EASTFACING,
    WESTFACING,
    NORTHFACING,
    SOUTHFACING,
    PLAYERINPUT,
    CANSHOOT,
    BULLET,
    MONSTER,
    CORPSE,
    ONCORPSE,
    LOOTINGCORPSE,
    BURNINGCORPSE,
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

struct Corpse : public Component {};

struct OnCorpse : public Component 
{
    public:
        int corpseEntityId;
};

struct TimedComponent : public Component
{
    public:
        TimedComponent(int _totalNeeded) : elapsedMs(0), totalMsNeeded(_totalNeeded) {};
        int elapsedMs;
        int totalMsNeeded;
};

struct LootingCorpse : public TimedComponent
{
    public:
        LootingCorpse(int _totalNeeded = 400) : TimedComponent(_totalNeeded) {};
};

struct BurningCorpse : public TimedComponent
{
    public:
        BurningCorpse(int _totalNeeded = 600) : TimedComponent(_totalNeeded) {};
};

struct Life : public Component {
    public:
        Life(int _hp) : hp(_hp), damage(0) {}; 
        int hp;
        int damage;
};

struct Ammo : public Component {
    public:
        Ammo(int _ammo) : ammo(_ammo) {}; 
        int ammo;
};

struct Remove : public Component {};

struct Collidable : public Component {
    public:
        int msBetweenHits = 400;
        int currentMs;
};


#endif
