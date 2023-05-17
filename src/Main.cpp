#include "Engine.hpp"

int main(int argc, char *argv[])
{
    if (Engine::Init())
        Engine::Run();

    return 0;
}