#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
	const int WIDTH = 1280;
	const int HEIGHT = 800;
	SDL_Window *window;
	SDL_Renderer *renderer;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
		printf("SDL initialization failed: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Chess Engine", SDL_WINDOWPOS_CENTERED,
							  SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
							  SDL_WINDOW_SHOWN);
	if (!window) {
		printf("Window creation failed: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		printf("Renderer creation failed: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	bool window_should_close = false;
	while (!window_should_close) {
		SDL_Event event;
		if(SDL_PollEvent(&event) > 0) {
			printf("Events are polling\n");
			if(event.type == SDL_QUIT) {
				window_should_close = true;
			}

			if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
				window_should_close = true;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// render

		SDL_RenderPresent(renderer);
		SDL_Delay(100);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
