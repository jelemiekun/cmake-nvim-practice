#include <SDL.h>
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>

int main(int argc, char *argv[]) {
  spdlog::info("[MAIN]: Initiating program...");

  spdlog::info("[MAIN]: Initiating program variables...");
  bool running = false;
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  spdlog::info("[MAIN]: Program variables initiated successfully.");

  spdlog::info("[MAIN]: Initiating sdl...");
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    spdlog::error("[MAIN]: Failed to initiate SDL: {}", SDL_GetError());
    return 0;
  } else {
    spdlog::info("[MAIN]: SDL initiated successfully.");
  }

  spdlog::info("[MAIN]: Initiating SDL Window...");
  window = SDL_CreateWindow("Neovim - OpenGL", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 720, 480,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if (window) {
    spdlog::info("[MAIN]: SDL window initiated successfully.");

    running = true;
  } else {
    spdlog::error("[MAIN]: Failed to initiate SDL Window: {}", SDL_GetError());
    return 0;
  }

  spdlog::info("[MAIN]: Initiating SDL Renderer...");
  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer) {
    spdlog::info("[MAIN]: SDL Renderer initiated successfully.");
  } else {
    spdlog::error("[MAIN]: Failed to initiate SDL Renderer: {}",
                  SDL_GetError());
    return 0;
  }

  while (running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        running = false;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
  }

  spdlog::info("[MAIN]: Cleaning resources...");
  SDL_DestroyRenderer(renderer);
  spdlog::info("[MAIN]: Renderer destroyed.");
  SDL_DestroyWindow(window);
  spdlog::info("[MAIN]: Window destroyed.");
  SDL_Quit();
  spdlog::info("[MAIN]: SDL cleaned up. Program terminated successfully.");

  return 0;
}
