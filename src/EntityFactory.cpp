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

    player->addComponent(ComponentTypes::POSITION, p); 
    player->addComponent(ComponentTypes::VELOCITY, m); 
    player->addComponent(ComponentTypes::COLLIDABLE, new Collidable());

    return player;
}

