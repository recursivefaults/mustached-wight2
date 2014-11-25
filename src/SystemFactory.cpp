#include "SystemFactory.h"
#include "systems/MoveSystem.h"
#include "systems/MonsterSystem.h"
#include "systems/CollisionSystem.h"
#include "systems/FacingSystem.h"
#include "systems/ShootingSystem.h"
#include "systems/RemoveSystem.h"
#include "systems/DamageSystem.h"
#include "systems/CorpseSystem.h"
#include "systems/MonsterSpawningSystem.h"
#include "systems/ParticleSystem.h"


std::vector<System *> SystemFactory::constructSystems(const SoundEngine *engine)
{
    std::vector<System *> systems;
    systems.push_back(new MonsterSpawningSystem(engine));
    systems.push_back(new MoveSystem());
    systems.push_back(new MonsterSystem());
    systems.push_back(new FacingSystem());
    systems.push_back(new ShootingSystem(engine));
    systems.push_back(new CorpseSystem(engine));
    systems.push_back(new CollisionSystem(engine));
    systems.push_back(new DamageSystem(engine));
    systems.push_back(new ParticleSystem());
    systems.push_back(new RemoveSystem());
    return systems;
}
