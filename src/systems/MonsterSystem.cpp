#include "systems/MonsterSystem.h"
#include "Constants.h"

void System::MonsterSystem::update(int elapsedMs, World &world)
{
    for(auto monster : world.getEntitiesForType(ComponentTypes::MONSTER))
    {
        Vector2d *newDirection = nullptr;
        if(monster->hasComponent(ComponentTypes::TARGETING_PLAYER_BEHAVIOR))
        {
            newDirection = getTargetedVelocity(monster, world);
        }
        if(monster->hasComponent(ComponentTypes::WANDERING_BEHAVIOR))
        {
            newDirection = getWanderingVelocity(monster, elapsedMs, world);
        }

        //Adjust velocity in that direction
        Velocity *zombieVelocity = (Velocity *) monster->getComponent(ComponentTypes::VELOCITY);

        zombieVelocity->dx = newDirection->x * kZombieMoveVelocity;
        zombieVelocity->dy = newDirection->y * kZombieMoveVelocity;

        if(newDirection != nullptr)
        {
            delete(newDirection);
        }

        if(monster->hasComponent(ComponentTypes::STUNNED))
        {
            handleStun(monster, elapsedMs);
            return;
        }

    }
}
Vector2d *System::MonsterSystem::getTargetedVelocity(Entity *monster, World &world)
{
    //Get the player
    std::list<Entity*> players = world.getEntitiesForType(ComponentTypes::PLAYERINPUT);
    //Pick a player
    Entity *player = players.front();

    Position *playerPosition = (Position *)player->getComponent(ComponentTypes::POSITION);
    Position *zombiePosition = (Position *)monster->getComponent(ComponentTypes::POSITION);
    Vector2d vel(playerPosition->x - zombiePosition->x, playerPosition->y - zombiePosition->y);
    Vector2d unitVel = vel.unit();
    return new Vector2d(unitVel.x, unitVel.y);
}

Vector2d *System::MonsterSystem::getWanderingVelocity(Entity *monster, int elapsedMs, World &world)
{
    WanderingBehavior *target = (WanderingBehavior *) monster->getComponent(ComponentTypes::WANDERING_BEHAVIOR);
    target->elapsedMs += elapsedMs;

    Velocity *vel = (Velocity *) monster->getComponent(ComponentTypes::VELOCITY);
    Vector2d unit(vel->dx, vel->dy);
    unit = unit.unit();

    if(target->elapsedMs >= target->totalMsNeeded)
    {
        //Change direction
        target->elapsedMs = 0;
        std::uniform_int_distribution<int> directions(0, 2);
        unit.x = directions(*engine->getRandomGenerator()) - 1.0f;
        unit.y = directions(*engine->getRandomGenerator()) - 1.0f;
        unit = unit.unit();
    }
    return new Vector2d(unit.x, unit.y);
}

void System::MonsterSystem::handleStun(Entity *monster, int elapsedMs)
{
    Velocity *zombieVelocity = (Velocity *) monster->getComponent(ComponentTypes::VELOCITY);
    Stunned *stun = (Stunned *) monster->getComponent(ComponentTypes::STUNNED);
    zombieVelocity->dx = 0.0f;
    zombieVelocity->dy = 0.0f;
    stun->elapsedMs += elapsedMs;
    if(stun->elapsedMs >= stun->totalMsNeeded)
    {
        monster->removeComponent(ComponentTypes::STUNNED);
    }

}
