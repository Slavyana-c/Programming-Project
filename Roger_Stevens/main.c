/*
main.c
Shows the menu
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constants.h"
#include "options.h"

int GAME_MODE;
char LVL_TEXT[20];
int LVL_NUM;
int LIVES;
int MOVES;
int BOOKS;

int main(int argc, char *argv[])
{
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *menu = NULL;
  SDL_Event event;


  // Initialize SDL2
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Roger Stevens",
                        SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        WINDOW_WIDTH, WINDOW_HEIGHT,
                        SDL_WINDOW_SHOWN);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  menu = IMG_LoadTexture(renderer, "images/menu.jpg");

  GAME_MODE = MENU;

  // Event loop
  while (GAME_MODE != QUIT)
  {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
          // Close the widow
          case SDL_QUIT:
              GAME_MODE = QUIT;
              break;

          // Key options
          case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
              {
                  case SDLK_ESCAPE:
                    GAME_MODE = QUIT;
                    break;

                  case SDLK_1:
                    GAME_MODE = PLAY;
                    option(renderer);
                    break;

                  case SDLK_2:
                    GAME_MODE = CONTINUE;
                    option(renderer);
                    break;

                  case SDLK_3:
                    GAME_MODE = EDIT;
                    option(renderer);
                    break;

                  case SDLK_4:
                    GAME_MODE = CUSTOM;
                    option(renderer);
                    break;
              }
              break;
      }

      // Render the screen
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, menu, NULL, NULL);
      if(GAME_MODE != QUIT) SDL_RenderPresent(renderer);
    }

    // Clear sdl
    SDL_DestroyTexture(menu);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
