#ifndef _BASE_COMPONENT_H_
#define _BASE_COMPONENT_H_

class Entity;

class BaseComponent
{
public:
    inline BaseComponent() {}
    inline virtual ~BaseComponent() {}

    virtual void Init() = 0;
    virtual void Update(float deltaTime) = 0;

    template <typename T>
    T *GetComponent()
    {
        return dynamic_cast<T *>(this);
    }

    inline Entity *GetOwner()
    {
        return owner;
    }

protected:
    Entity *owner;

    friend Entity;
};

#endif