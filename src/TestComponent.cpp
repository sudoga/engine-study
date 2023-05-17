#include <iostream>
#include <SDL2/SDL.h>
#include "TestComponent.hpp"
#include "Entity.hpp"
#include "Engine.hpp"

void TestComponent::Init()
{
    otherTest = nullptr;
    std::cout << "Init!" << std::endl;
}

void TestComponent::Update(float deltaTime)
{
    auto keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_SPACE]) {
        otherTest = Engine::GetWorld().CreateEntity();
    }
    if (keys[SDL_SCANCODE_F]) {
        Engine::GetWorld().DeleteEntity(otherTest);
        otherTest = nullptr;
    }
}
