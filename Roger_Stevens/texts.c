#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "globals.h"
#include "constants.h"
#include "files.h"
#include "texts.h"

// Writes saving..
void savedMessage(SDL_Renderer *renderer, TTF_Font *font)
{
    SDL_Rect textPosition;
    char saved[15] = "Saving...";

    // Text position
    textPosition.y = TEXT_Y;
    textPosition.h = TEXT_H;
    textPosition.w = TEXT_W;

    // Set color to white
    SDL_Color color = { 255, 255, 255 };

    textPosition.x = SAVE_X;
    SDL_Surface * surface = TTF_RenderText_Solid(font,
    saved, color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &textPosition);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

// Renders the text
void renderText(SDL_Renderer *renderer, TTF_Font *font)
{
  SDL_Rect textPosition;
  char fixedMoves[20] = {0}, fixedBooks[20] = {0},
  fixedLevel[20] = {0}, fixedLives[20], numstr[5] = {0};

  strcpy(fixedLevel, "Level: ");
  strcpy(fixedMoves, "Moves: ");
  strcpy(fixedBooks, "Books: ");
  strcpy(fixedLives, "Lives: ");

  // Set text position
  textPosition.y = TEXT_Y;
  textPosition.h = TEXT_H;
  textPosition.w = TEXT_W;


  // Set color to white
  SDL_Color color = { 255, 255, 255 };

  // Set the level
  strcat(fixedLevel, LVL_TEXT);

  sprintf(numstr, "%d", MOVES);
  strcat(fixedMoves, numstr);

  sprintf(numstr, "%d", BOOKS);
  strcat(fixedBooks, numstr);

  sprintf(numstr, "%d", LIVES);
  strcat(fixedLives, numstr);

  // Copy to renderer
  textPosition.x = LVL_X;
  SDL_Surface * surface = TTF_RenderText_Solid(font,
  fixedLevel, color);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_RenderCopy(renderer, texture, NULL, &textPosition);

  textPosition.x = LIVES_X;
  surface = TTF_RenderText_Solid(font,
  fixedLives, color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_RenderCopy(renderer, texture, NULL, &textPosition);


  textPosition.x = MOVES_X;
  surface = TTF_RenderText_Solid(font,
  fixedMoves, color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_RenderCopy(renderer, texture, NULL, &textPosition);


  textPosition.x = BOOKS_X;
  surface = TTF_RenderText_Solid(font,
  fixedBooks, color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_RenderCopy(renderer, texture, NULL, &textPosition);


  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

}
