#include "World.hpp"
#include "TestComponent.hpp"

World::World(std::string name)
{
}

World::~World()
{
}

void World::Load()
{
    auto worldTest = CreateEntity();
    worldTest->AddComponent(new TestComponent());
}

void World::Unload()
{
}

void World::Update(float deltaTime)
{
    if (mustInit.size())
    {
        for (auto e : mustInit)
            e->Init();
        mustInit.clear();
    }

    if (mustDelete.size())
    {
        for (int i = mustDelete.size() - 1; i >= 0; --i)
        {
            decltype(entities)::iterator toRemove = 
                entities.begin() + mustDelete[i];

            delete *toRemove;
            entities.erase(toRemove);
        }
        mustDelete.clear();
    }

    size_t eSize = entities.size();
    for (size_t i = 0; i < eSize; ++i)
        entities[i]->Update(deltaTime);
}

Entity *World::CreateEntity()
{
    Entity *entity = new Entity();
    entities.push_back(entity);
    mustInit.push_back(entity);
    return entity;
}

bool World::DeleteEntity(Entity *entity)
{
    for (size_t i = 0; i < entities.size(); ++i)
    {
        if (entities[i] == entity)
        {
            mustDelete.push_back(i);
            return true;
        }
    }
    return false;
}
