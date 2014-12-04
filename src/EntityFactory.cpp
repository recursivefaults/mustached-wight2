#include "EntityFactory.h"
#include "Components.h"
#include "Constants.h"
#include <chrono>


EntityFactory::EntityFactory()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator = new std::default_random_engine(seed);

    lifeDistribution = std::uniform_int_distribution<int>(1, 3);
    ammoDistribution = std::uniform_int_distribution<int>(1, 5);
    frameDistribution = std::uniform_int_distribution<int>(5, 15);
    velocityDistribution = std::uniform_real_distribution<float>(-1.0f, 1.0f);
}

EntityFactory::~EntityFactory()
{
    delete(generator);
}

Entity *EntityFactory::createPlayer() 
{
    Entity *player = new Entity();

    //Components
    Position *p = new Position();
    p->x = 400;
    p->y = 300;

    Velocity *m = new Velocity();
    m->dx = 0.0f;
    m->dy = 0.0f;

    RenderRect *r = new RenderRect();
    r->spriteName = "Hero.png";
    r->rect = {p->x, p->y, 16, 16};
    r->color = {10, 200, 10};

    player->addComponent(ComponentTypes::POSITION, p); 
    player->addComponent(ComponentTypes::VELOCITY, m); 
    player->addComponent(ComponentTypes::RENDERRECT, r);
    player->addComponent(ComponentTypes::LIFE, new Life(3));
    player->addComponent(ComponentTypes::AMMO, new Ammo(10));
    player->addComponent(ComponentTypes::PLAYERINPUT, new PlayerInput());
    player->addComponent(ComponentTypes::CANSHOOT, new CanShoot());
    player->addComponent(ComponentTypes::FACING, new Facing());
    player->addComponent(ComponentTypes::COLLIDABLE, new Collidable());

    return player;
}

Entity *EntityFactory::createSpawnCounter()
{
    Entity *counter = new Entity();
    counter->addComponent(ComponentTypes::CORPSE_COUNTER, new CorpseCounter());
    return counter;
}

Entity *EntityFactory::createLootedCorpse(Position *position)
{
    Entity *corpse = new Entity();

    RenderRect *r = new RenderRect();
    r->rect.w = 16;
    r->rect.h = 16;
    r->color = {168, 132, 0};
    r->spriteName = "Corpses.png";
    r->textureRect = {16, 0, 16, 16};

    corpse->addComponent(ComponentTypes::CORPSE, new Corpse());
    corpse->addComponent(ComponentTypes::POSITION, position);
    corpse->addComponent(ComponentTypes::RENDERRECT, r);
    return corpse;
}

Entity *EntityFactory::createCorpse(Position *position)
{
    Entity *corpse = new Entity();

    RenderRect *r = new RenderRect();
    r->rect.w = 16;
    r->rect.h = 16;
    r->color = {168, 132, 0};
    r->spriteName = "Corpses.png";
    r->textureRect = {0, 0, 16, 16};

    corpse->addComponent(ComponentTypes::CORPSE, new Corpse());
    corpse->addComponent(ComponentTypes::AMMO, new Ammo(ammoDistribution(*generator)));
    corpse->addComponent(ComponentTypes::POSITION, position);
    corpse->addComponent(ComponentTypes::COLLIDABLE, new Collidable());
    corpse->addComponent(ComponentTypes::RENDERRECT, r);
    return corpse;
}

Entity *EntityFactory::createZombie(Position *position)
{
    Entity *zombie = new Entity();

    int life = lifeDistribution(*generator);

    RenderRect *r = new RenderRect();
    r->rect.w = 16;
    r->rect.h = 16;
    r->color = {40, 180, 80};
    r->spriteName = "Zombie.png";

    zombie->addComponent(ComponentTypes::RENDERRECT, r);
    zombie->addComponent(ComponentTypes::LIFE, new Life(life));
    zombie->addComponent(ComponentTypes::VELOCITY, new Velocity());
    zombie->addComponent(ComponentTypes::MONSTER, new Monster());
    zombie->addComponent(ComponentTypes::FACING, new Facing());
    zombie->addComponent(ComponentTypes::COLLIDABLE, new Collidable());
    zombie->addComponent(ComponentTypes::POSITION, position);

    std::uniform_real_distribution<float> wanderingChance(0.0f, 1.0f);
    if(wanderingChance(*generator) < kWanderingMonsterChance)
    {
        SDL_Log("Wandering monster created");
        zombie->addComponent(ComponentTypes::WANDERING_BEHAVIOR, new WanderingBehavior());
    }
    else
    {
        SDL_Log("Targeting monster created");
        zombie->addComponent(ComponentTypes::TARGETING_PLAYER_BEHAVIOR, new TargetingPlayerBehavior());
    }

    return zombie;
}

Entity *EntityFactory::createBullet(Position *initialPosition, Velocity *initialVelocity)
{
    Entity *bullet = new Entity();
    RenderRect *render = new RenderRect();
    render->rect.w = 2;
    render->rect.h = 2;
    if(initialVelocity->dx != 0) 
    {
        render->rect.w = 4;
    }
    else
    {
        render->rect.h = 4;
    }
    render->color = {200, 10, 10};

    Position *p = new Position();
    p->x = initialPosition->x + 8;
    p->y = initialPosition->y + 8;

    bullet->addComponent(ComponentTypes::POSITION, p);
    bullet->addComponent(ComponentTypes::VELOCITY, initialVelocity);
    bullet->addComponent(ComponentTypes::COLLIDABLE, new Collidable());
    bullet->addComponent(ComponentTypes::RENDERRECT, render);
    bullet->addComponent(ComponentTypes::BULLET, new Bullet());

    return bullet;
}
Entity *EntityFactory::createBloodParticle(Position *startingPostion, Velocity *startingVelocity)
{
    Entity *particle = new Entity();

    Position *position = new Position();

    //TODO: Fix this!
    position->x = startingPostion->x + 8;
    position->y = startingPostion->y + 8;

    Velocity *velocity = new Velocity();

    velocity->dx = kBloodVelocity;
    velocity->dy = kBloodVelocity;

    if(startingVelocity->dx != 0)
    {
        if(startingVelocity->dx < 0)
        {
            velocity->dx *= -1.0f;
        }
        velocity->dy *= velocityDistribution(*generator);
    }
    if(startingVelocity->dy != 0)
    {
        if(startingVelocity->dy < 0)
        {
            velocity->dy *= -1.0f;
        }
        velocity->dx *= velocityDistribution(*generator);
    }

    SDL_Log("Particle Velocity: %f, %f", velocity->dx, velocity->dy);

    RenderRect *render = new RenderRect();
    render->rect.w = 2;
    render->rect.h = 2;
    render->color = {200, 60, 20};

    int particleLifespan = frameDistribution(*generator);
    
    particle->addComponent(ComponentTypes::POSITION, position);
    particle->addComponent(ComponentTypes::VELOCITY, velocity);
    particle->addComponent(ComponentTypes::RENDERRECT, render);
    particle->addComponent(ComponentTypes::PARTICLE, new Particle(particleLifespan));

    return particle;
}

