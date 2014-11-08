#include "systems/MonsterSystem.h"
#include "Constants.h"

void MonsterSystem::update(int elapsedMs, World &world)
{
    for(auto monster : world.getEntitiesForType(ComponentTypes::MONSTER))
    {
        //Get the player
        std::list<Entity*> players = world.getEntitiesForType(ComponentTypes::PLAYERINPUT);
        //Pick a player
        Entity *player = players.front();

        //Calculate vector towards player
        Velocity diff = Velocity();
        Position *playerPosition = (Position *)player->getComponent(ComponentTypes::POSITION);
        Position *zombiePosition = (Position *)monster->getComponent(ComponentTypes::POSITION);
        diff.dx = playerPosition->x - zombiePosition->x;
        diff.dy = playerPosition->y - zombiePosition->y;

        //Adjust velocity in that direction
        Velocity *zombieVelocity = (Velocity *) monster->getComponent(ComponentTypes::VELOCITY);
        if(diff.dx == 0.0f)
            zombieVelocity->dx = 0.0f;
        if(diff.dy == 0.0f)
            zombieVelocity->dy = 0.0f;
        if(diff.dx < 0.0f)
            zombieVelocity->dx = -kZombieMoveVelocity;
        if(diff.dx > 0.0f)
            zombieVelocity->dx = kZombieMoveVelocity;
        if(diff.dy < 0.0f)
            zombieVelocity->dy = -kZombieMoveVelocity;
        if(diff.dx > 0.0f)
            zombieVelocity->dy = kZombieMoveVelocity;
        
    }
}