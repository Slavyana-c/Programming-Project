#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "constants.h"
#include "globals.h"
#include "files.h"
#include "texts.h"

void ShowWin(SDL_Renderer *renderer)
{
  TTF_Init();
    SDL_Texture *win = NULL;
    SDL_Event event;
    int bestMoves, bestBooks;

      TTF_Font * font = TTF_OpenFont("fonts/arial.ttf", 100);

    win = IMG_LoadTexture(renderer, "images/win.jpg");

    highScore(&bestMoves, &bestBooks);

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
                showScore(renderer, font, bestMoves, bestBooks);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(win);

    TTF_Quit();
}

void ShowLose(SDL_Renderer *renderer)
{
  TTF_Init();
  TTF_Font * font = TTF_OpenFont("fonts/arial.ttf", 100);
  SDL_Texture *lose = NULL;
  SDL_Event event;
      int bestMoves, bestBooks;

    highScore(&bestMoves, &bestBooks);
  lose = IMG_LoadTexture(renderer, "images/lose.jpg");

  // Event loop
  while (GAME_MODE != MENU && GAME_MODE != QUIT)
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
            showScore(renderer, font, bestMoves, bestBooks);
      SDL_RenderPresent(renderer);
  }
  SDL_DestroyTexture(lose);

  TTF_Quit();
}
