#include "systems/FacingSystem.h"


void System::FacingSystem::update(int elapsedMs, World &world, Room &room)
{
    for(auto entity : world.getEntitiesForType(ComponentTypes::FACING))
    {
        Component *newFacing = nullptr;
        ComponentTypes type = ComponentTypes::NORTHFACING;

        if(world.wasKeyPressed(SDLK_a)) {
            newFacing = new WestFacing();
            type = ComponentTypes::WESTFACING;
        }
        if(world.wasKeyPressed(SDLK_d)) {
            newFacing = new EastFacing();
            type = ComponentTypes::EASTFACING;
        }
        if(world.wasKeyPressed(SDLK_w)) {
            newFacing = new NorthFacing();
            type = ComponentTypes::NORTHFACING;
        }
        if(world.wasKeyPressed(SDLK_s)) {
            newFacing = new SouthFacing();
            type = ComponentTypes::SOUTHFACING;
        }

        if(newFacing != nullptr)
        {
            //Clean up old facings, and add this one if it's new
            entity->removeComponent(ComponentTypes::SOUTHFACING);
            entity->removeComponent(ComponentTypes::NORTHFACING);
            entity->removeComponent(ComponentTypes::EASTFACING);
            entity->removeComponent(ComponentTypes::WESTFACING);

            entity->addComponent(type, newFacing);
        }
    }

}
