/*
endgame.c
Shows the screen at the end of the game
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "constants.h"
#include "globals.h"
#include "files.h"
#include "texts.h"

// Displays the game over screen
void showEnd(SDL_Renderer *renderer)
{
  TTF_Init();
  SDL_Texture *screen = NULL;
  SDL_Event event;
  int bestMoves, bestBooks;

  TTF_Font * font = TTF_OpenFont("fonts/arial.ttf", 100);

  if(GAME_MODE == WIN) screen = IMG_LoadTexture(renderer, "images/win.jpg");
  else screen = IMG_LoadTexture(renderer, "images/lose.jpg");

  // Check the high score unless it's a custom level
  if(LVL_NUM != 0) highScore(&bestMoves, &bestBooks);

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
      switch(event.key.keysym.sym)
      {
        case SDLK_ESCAPE:
        GAME_MODE = MENU;
        break;
      }
    }

    // Render the screen
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screen, NULL, NULL);
    showScore(renderer, font, bestMoves, bestBooks);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyTexture(screen);
  TTF_CloseFont(font);

  TTF_Quit();
}
