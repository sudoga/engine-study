#ifndef _TEST_COMPONENT_H_
#define _TEST_COMPONENT_H_
#include "BaseComponent.hpp"

class TestComponent : public BaseComponent
{
private:
    Entity *otherTest;
public:
    void Init() override;
    void Update(float deltaTime) override;
};

#endif