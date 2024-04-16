#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
  const int WIDTH = 800;
  const int HEIGHT = 800;
  const int SQUARE_SIZE = WIDTH / 8;

  SDL_Window *window;
  SDL_Renderer *renderer;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
    printf("SDL initialization failed: %s\n", SDL_GetError());
    return 1;
  }

  window =
      SDL_CreateWindow("Chess Engine", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
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
    while (SDL_PollEvent(&event) > 0) {
      if (event.type == SDL_QUIT) {
        window_should_close = true;
      }

      if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        window_should_close = true;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw chessboard
    SDL_Rect rect;
    rect.w = SQUARE_SIZE;
    rect.h = SQUARE_SIZE;

    // Loop through each square of the chessboard
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        // Set the position of the square
        rect.x = col * SQUARE_SIZE;
        rect.y = row * SQUARE_SIZE;

        // Alternate the color of the square
        if ((row + col) % 2 == 0) {
          SDL_SetRenderDrawColor(renderer, 0xc9, 0xa9, 0x7b, 255); // white
        } else {
          SDL_SetRenderDrawColor(renderer, 0x2c, 0x18, 0x08, 255); // black
        }

        // Draw the square
        SDL_RenderFillRect(renderer, &rect);
      }
    }
    // render

    SDL_RenderPresent(renderer);
    SDL_Delay(100);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
