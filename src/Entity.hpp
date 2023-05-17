#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <vector>
#include "BaseComponent.hpp"
#include "Transform.hpp"

class Entity
{
private:
    std::vector<BaseComponent *> components;

public:
    Transform transform;

public:
    Entity();
    ~Entity();

    void Init();
    void Update(float deltaTime);

    void AddComponent(BaseComponent *component);

    template <typename T>
    T *GetComponent() {
        for (auto c : components)
        {
            if (T *t = dynamic_cast<T*>(c); t)
                return t;
        }
        return nullptr;
    }
};

#endif