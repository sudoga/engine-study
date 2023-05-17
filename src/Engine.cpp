#include "Engine.hpp"

namespace Engine
{
    namespace
    {
        SDL_Window *window;
        SDL_Renderer *renderer;
        World world{"test"};
    }

    bool Init()
    {
        SDL_Init(SDL_INIT_VIDEO);

        window = SDL_CreateWindow("engine", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  640, 480, SDL_WINDOW_RESIZABLE);

        renderer = SDL_CreateRenderer(window, -1, 0);

        return true;
    }

    void HandleEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                exit(0);
        }
    }

    void Draw()
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect rect = (SDL_Rect) {
            .x = 32,
            .y = 32,
            .w = 32,
            .h = 32,
        };

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);
    }

    void Update(float deltaTime)
    {
        world.Update(deltaTime);
    }

    void Run()
    {
        world.Load();

        Uint64 now = SDL_GetPerformanceCounter();
        Uint64 last = now - 1;

        while (1)
        {
            last = now;
            now = SDL_GetPerformanceCounter();

            float deltaTime = static_cast<float>((now - last) * 1000.0 / (double)SDL_GetPerformanceFrequency());

            HandleEvents();

            Update(deltaTime);

            Draw();
        }
    }

    World &GetWorld()
    {
        return world;
    }
}