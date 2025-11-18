#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 900
#define HEIGHT 600

void Draw_Circle(SDL_Renderer *renderer, double x, double y, double radius)
{
    for (int i = x - radius; i < x + radius; i++)
    {
        for (int j = y - radius; j < y + radius; j++)
        {
            // double dist = sqrt(pow(((double)i)-x, 2) + pow(((double)j)-y, 2));
            double dist = sqrt((i - x) * (i - x) + (j - y) * (j - y));
            if (dist < radius)
            {
                SDL_RenderDrawPoint(renderer, i, j);
            }
        }
    }
}

int main()
{
    printf("Hello Circle\n");

    // Initialize the project
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Bouncing Circle",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT, 0);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, 0);

    SDL_RenderClear(renderer);

    // Clear screen (background)
    SDL_Rect background_rect = (struct SDL_Rect){0, 0, WIDTH, HEIGHT};

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // Opaque black
    SDL_RenderFillRect(renderer, &background_rect);

    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF); // Green
    // Draw a single green point
    // SDL_RenderDrawPoint(renderer, 50, 50);
    // Draw Circle
    Draw_Circle(renderer, 50, 50, 60);

    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    // Clean Up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
