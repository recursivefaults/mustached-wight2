#include "EntityFactory.h"
#include "Components.h"
#include <random>

Entity *EntityFactory::createPlayer() 
{
    Entity *player = new Entity();

    //Components
    Position *p = new Position();
    p->x = 10;
    p->y = 10;

    Velocity *m = new Velocity();
    m->dx = 0.0f;
    m->dy = 0.0f;

    RenderRect *r = new RenderRect();
    r->rect.x = p->x;
    r->rect.y = p->y;
    r->rect.w = 16;
    r->rect.h = 16;
    r->r = 10;
    r->b = 200;
    r->g = 10;

    player->addComponent(ComponentTypes::POSITION, p); 
    player->addComponent(ComponentTypes::VELOCITY, m); 
    player->addComponent(ComponentTypes::RENDERRECT, r);
    player->addComponent(ComponentTypes::LIFE, new Life(3));
    player->addComponent(ComponentTypes::AMMO, new Ammo(5));
    player->addComponent(ComponentTypes::PLAYERINPUT, new PlayerInput());
    player->addComponent(ComponentTypes::CANSHOOT, new CanShoot());
    player->addComponent(ComponentTypes::FACING, new Facing());
    player->addComponent(ComponentTypes::COLLIDABLE, new Collidable());

    return player;
}

Entity *EntityFactory::createCorpse(Position *position)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,3);

    Entity *corpse = new Entity();

    RenderRect *r = new RenderRect();
    r->rect.w = 16;
    r->rect.h = 16;
    r->r = 168;
    r->b = 132;
    r->g = 0;

    corpse->addComponent(ComponentTypes::CORPSE, new Corpse());
    corpse->addComponent(ComponentTypes::AMMO, new Ammo(distribution(generator)));
    corpse->addComponent(ComponentTypes::POSITION, position);
    corpse->addComponent(ComponentTypes::COLLIDABLE, new Collidable());
    corpse->addComponent(ComponentTypes::RENDERRECT, r);
    return corpse;
}

Entity *EntityFactory::createZombie(Position *position)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,3);

    Entity *zombie = new Entity();

    int life = distribution(generator);

    RenderRect *r = new RenderRect();
    r->rect.w = 16;
    r->rect.h = 16;
    r->r = 40;
    r->g = 180;
    r->b = 80;

    zombie->addComponent(ComponentTypes::RENDERRECT, r);
    zombie->addComponent(ComponentTypes::LIFE, new Life(life));
    zombie->addComponent(ComponentTypes::VELOCITY, new Velocity());
    zombie->addComponent(ComponentTypes::MONSTER, new Monster());
    zombie->addComponent(ComponentTypes::FACING, new Facing());
    zombie->addComponent(ComponentTypes::COLLIDABLE, new Collidable());
    zombie->addComponent(ComponentTypes::POSITION, position);
    return zombie;
}

Entity *EntityFactory::createBullet(Position *initialPosition, Velocity *initialVelocity)
{
    Entity *bullet = new Entity();
    RenderRect *render = new RenderRect();
    render->rect.w = 8;
    render->rect.h = 8;
    render->r = 200;
    render->g = 10;
    render->b = 10;

    bullet->addComponent(ComponentTypes::POSITION, initialPosition);
    bullet->addComponent(ComponentTypes::VELOCITY, initialVelocity);
    bullet->addComponent(ComponentTypes::COLLIDABLE, new Collidable());
    bullet->addComponent(ComponentTypes::RENDERRECT, render);
    bullet->addComponent(ComponentTypes::BULLET, new Bullet());

    return bullet;
}

