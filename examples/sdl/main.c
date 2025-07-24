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

    

   printf("SUCCESS!\n"); 



return 0;
}
