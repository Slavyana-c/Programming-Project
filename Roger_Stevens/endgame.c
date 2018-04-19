#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constants.h"
#include "globals.h"

void ShowWin(SDL_Renderer *renderer)
{
    SDL_Texture *win = NULL;
    SDL_Event event;

    win = IMG_LoadTexture(renderer, "images/win.jpg");

    // Event loop
    while (GAME_MODE != MENU)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            // Close the widow
            case SDL_QUIT:
                GAME_MODE = QUIT;
                break;

            // Go to menu
            case SDL_KEYDOWN:
                GAME_MODE = MENU;
                break;
        }

        // Render the screen
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, win, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(win);
}

void ShowLose(SDL_Renderer *renderer)
{
  SDL_Texture *lose = NULL;
  SDL_Event event;

  lose = IMG_LoadTexture(renderer, "images/lose.jpg");

  // Event loop
  while (GAME_MODE != MENU)
  {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
          // Close the widow
          case SDL_QUIT:
              GAME_MODE = QUIT;
              break;

          // Go to menu
          case SDL_KEYDOWN:
              GAME_MODE = MENU;
              break;
      }

      // Render the screen
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, lose, NULL, NULL);
      SDL_RenderPresent(renderer);
  }
  SDL_DestroyTexture(lose);

}
