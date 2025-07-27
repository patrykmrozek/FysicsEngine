#include <physics/fysics.h>
#include <SDL2/SDL.h>

#define WIDTH 1000
#define HEIGHT 800

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    //window
    SDL_Window* window = SDL_CreateWindow(
        "fySDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return 1;
    }
    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //renderer
    SDL_Renderer* renderer = SDL_GetRenderer(window);
    if (!renderer) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return 1;
    }
    
    //world init
    fyWorldConfig config;
    config.max_bodies = 5;
    fyWorld* world = fyWorld_Create(&config);
    fyBody* body = fyWorld_CreateBody(world, 10.0f);
    fyBody_SetPosition(body, 100.0f, 100.0f);


    Uint32 prev_time = SDL_GetTicks();
    SDL_RaiseWindow(window);
    SDL_PumpEvents();
    SDL_Event event;
    int running = 1;
    while (running) {
        //delta time
        Uint32 curr_time = SDL_GetTicks();
        float delta_time = (curr_time - prev_time) / 1000.0f;
        prev_time = curr_time;


        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
        
        fyWorld_Step(world, delta_time);

        //SDL_Rect using fyBody info
        fyVec2 body_pos = fyBody_GetPosition(body);
        SDL_Rect rect = {body_pos.x, body_pos.y , 50, 50};
    
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect); 
        
        SDL_RenderPresent(renderer);

    }

    fyWorld_Destroy(world);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
