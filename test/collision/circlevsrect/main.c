#include <physics/fysics.h>
#include <physics/collision/aabb.h>
#include <physics/core/body.h>
#include <physics/collision/shape.h>
#include <physics/collision/collision_detection.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 800

void draw_circle(SDL_Renderer* renderer, fyBody* body) {
    fyVec2 pos = body->position;
    float r = body->shape.data.circle.radius;
	for (double x=pos.x-r; x<pos.x+r; x++) {
		for (double y=pos.y-r; y<pos.y+r; y++) {
            float distance = fyVec2_Dist(pos, (fyVec2){x, y});
			if (distance < r) {
				SDL_Rect pixel =(SDL_Rect){x, y, 1, 1};
				SDL_RenderFillRect(renderer, &pixel);
			}
		}
	}
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "TEST - circlevsrect",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        printf("CREATEWINDOW ERROR: %s\n", SDL_GetError());
        return 1;
    }

    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Renderer* renderer = SDL_GetRenderer(window);
    if (!renderer) {
        printf("GETRENDERER ERROR: %s\n", SDL_GetError());
    return 1;
    }

    fyWorldConfig config;
    config.max_bodies = 2;
    fyWorld* world = fyWorld_Create(&config);
    fyBody* body_c = fyWorld_CreateBody(world, 50.0f);
    fyBody* body_r = fyWorld_CreateBody(world, 90.0f);
    
    fyBody_SetPosition(body_c, 200.0f, 200.0f);
    const float RADIUS1 = 100.0f;
    fyBody_SetCircleCollider(body_c, RADIUS1);
    
    fyBody_SetPosition(body_r, 500.0f, 100.0f);
    float const WIDTH2 = 100.0f;
    float const HEIGHT2 = 400.0f;
    fyBody_SetRectangleCollider(body_r, WIDTH2, HEIGHT2);
   

    const float FIXED_DT = 1.0f / 60.0f;
    float accumulator = 0.0f;
    Uint32 prev_time = SDL_GetTicks();

    SDL_RaiseWindow(window);
    SDL_PumpEvents();
    SDL_Event event;
    int running = 1;
    while (running) {

        Uint32 curr_time = SDL_GetTicks();
        accumulator += (curr_time - prev_time) / 1000.0f;
        prev_time = curr_time;
        
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
       
        while (accumulator >= FIXED_DT) {
            fyWorld_Step(world, FIXED_DT);
            accumulator -= FIXED_DT;
        }


        fyBody_AddForce(body_c, 3000.0f, -50.0f);
        fyBody_AddForce(body_r, -500.0f, 200.0f);
        
        fyVec2 body_r_pos = fyBody_GetPosition(body_r);
        SDL_Rect rect_r = {
            body_r_pos.x - WIDTH2/2,
            body_r_pos.y - HEIGHT2/2,
            WIDTH2,
            HEIGHT2
        };

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        fyCollisionInfo info;
        if (fyCollision_CircleVsRect(body_c, body_r, &info)) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        draw_circle(renderer, body_c);
        SDL_RenderFillRect(renderer, &rect_r);
        
        SDL_RenderPresent(renderer);

        
    }

    fyWorld_Destroy(world);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;


}
