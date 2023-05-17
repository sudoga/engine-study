#ifndef _WORLD_H_
#define _WORLD_H_
#include <string>
#include <vector>
#include "Entity.hpp"

class World
{
private:
    std::string name;
    std::string nextWorld, lastWorld;
    std::vector<Entity *> entities;
    std::vector<Entity *> mustInit;
    std::vector<size_t> mustDelete;

public:
    World(std::string name);
    ~World();

    void Load();
    void Unload();

    void Init();
    void Update(float deltaTime);

    Entity *CreateEntity();
    bool DeleteEntity(Entity *entity);

    inline const std::string &GetName()
    {
        return name;
    }
};

#endif