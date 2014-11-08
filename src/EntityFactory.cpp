#include "EntityFactory.h"
#include "Components.h"

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

    player->addComponent(ComponentTypes::POSITION, p); 
    player->addComponent(ComponentTypes::VELOCITY, m); 
    player->addComponent(ComponentTypes::RENDERRECT, r);
    player->addComponent(ComponentTypes::FACING, new Facing());
    player->addComponent(ComponentTypes::PLAYERINPUT, new PlayerInput());
    player->addComponent(ComponentTypes::CANSHOOT, new CanShoot());
    player->addComponent(ComponentTypes::COLLIDABLE, new Collidable());

    return player;
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

