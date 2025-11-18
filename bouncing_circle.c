#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 900
#define HEIGHT 600

typedef struct {
	double x;
	double y;
	double radius;
	double vx;
	double vy;
} Circle;


// Draw a filled circle
void Draw_Circle(SDL_Renderer *renderer, double x, double y, double radius)
{
	for (int i = x - radius; i <= x + radius; i++)
		for (int j = y - radius; j <= y + radius; j++)
			if (sqrt((i - x)*(i - x) + (j - y)*(j - y)) <= radius)
				SDL_RenderDrawPoint(renderer, i, j);
}

// Move circle and handle collisions with window edges
void Update_Circle(Circle *c)
{
	c->x += c->vx;
	c->y += c->vy;
	// Left edge
	if(c->x - c->radius < 0) {
		c->x = c->radius;
		c->vx = -c->vx;
	};
	// Right Edge
	if(c->x + c->radius > WIDTH) {
		c->x = WIDTH - c->radius;
		c->vx = -c->vx;
	};
	// Top Edge
	if(c->y - c->radius < 0) {
		c->y = c->radius;
		c->vy = -c->vy;
	};
	// Bottom Edge
	if(c->y + c->radius > HEIGHT) {
		c->y = HEIGHT - c->radius;
		c->vy = -c->vy;
	};
}

// Draw background and circle
void Render(SDL_Renderer *renderer, Circle *c)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);	// black background
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);	// green circle
	Draw_Circle(renderer, c->x, c->y, c->radius);

	SDL_RenderPresent(renderer);
}

// Initialize SDL and return renderer
SDL_Renderer* InitSDL(SDL_Window **window)
{
	SDL_Init(SDL_INIT_VIDEO);
	*window = SDL_CreateWindow("Bounding Circle",
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				WIDTH, HEIGHT, 0);
	return SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
}

// Clean up SDL
void Cleanup(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main()
{
	SDL_Window *window;
	SDL_Renderer *renderer = InitSDL(&window);
	
	Circle ball = {200, 200, 60, 4.0, 3.0};
	int running = 1;
	SDL_Event event;

	while(running)
	{
		while(SDL_PollEvent(&event))
			if (event.type == SDL_QUIT)
				running = 0;
		
		Update_Circle(&ball);
		Render(renderer, &ball);

		SDL_Delay(16);	// -60 FPS
	}
	
	Cleanup(window, renderer);
	return 0;
}
