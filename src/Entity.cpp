#include "Entity.hpp"
#include <iostream>

Entity::Entity()
{
    std::cout << __FUNCTION__ << std::endl;
}

Entity::~Entity()
{
    for (auto c : components)
        delete c;
        
    std::cout << __FUNCTION__ << std::endl;
}

void Entity::Init()
{
    for (auto c : components)
        c->Init();
}

void Entity::Update(float deltaTime)
{
    for (auto c : components)
        c->Update(deltaTime);
}

void Entity::AddComponent(BaseComponent *component)
{
    component->owner = this;
    components.push_back(component);
}
