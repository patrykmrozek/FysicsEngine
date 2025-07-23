#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
    }
    
    SDL_Window* window = SDL_CreateWindow(
        "TEST",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000,
        800,
        SDL_WINDOW_SHOWN
    );

    SDL_RaiseWindow(window);
    
    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
