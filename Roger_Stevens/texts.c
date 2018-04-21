#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "globals.h"
#include "constants.h"
#include "files.h"


void showScore(SDL_Renderer *renderer, TTF_Font *font, int bestMoves, int bestBooks)
{
  SDL_Rect textPosition;

  // Text position
  textPosition.y = 700;
  textPosition.h = 40;
  textPosition.w = 150;

  char booksText[20] = "Books: ";
  char bestBooksText[20] = "High score: ";
  char movesText[20] = "Moves: ";
  char bestMovesText[20] = "High score: " ;
  char numstr[5];
  SDL_Surface * surface = NULL;
  SDL_Texture * texture = NULL;


  // Set color to white
  SDL_Color color = { 255, 255, 255 };

  if(GAME_MODE == WIN)
  {
    textPosition.y = 650;
    textPosition.x = LVL_X + 50;
    sprintf(numstr, "%d", MOVES);
    strcat(movesText, numstr);

    surface = TTF_RenderText_Solid(font,
    movesText, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &textPosition);


    textPosition.x = LVL_X + 500;
    textPosition.w = 250;

    sprintf(numstr, "%d", bestMoves);
    strcat(bestMovesText, numstr);
    surface = TTF_RenderText_Solid(font,
    bestMovesText, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &textPosition);

  }

  textPosition.y = 700;
  textPosition.x = LVL_X + 50;
  textPosition.w = 150;
  sprintf(numstr, "%d", BOOKS);
  strcat(booksText, numstr);


  surface = TTF_RenderText_Solid(font,
  booksText, color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_RenderCopy(renderer, texture, NULL, &textPosition);

  textPosition.x = LVL_X + 500;
    textPosition.w = 250;
  sprintf(numstr, "%d", bestBooks);
  strcat(bestBooksText, numstr);
  surface = TTF_RenderText_Solid(font,
  bestBooksText, color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_RenderCopy(renderer, texture, NULL, &textPosition);

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

}

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

    printf("reached saved\n" );
    textPosition.x = SAVE_X;
    SDL_Surface * surface = TTF_RenderText_Solid(font,
    saved, color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &textPosition);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);

    printf("reached saved done\n" );
}

// Renders the text
void renderText(SDL_Renderer *renderer, TTF_Font *font)
{
  SDL_Rect textPosition;
  char fixedMoves[20] = {0}, fixedBooks[20] = {0},
  fixedLives[20], numstr[5] = {0};

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
  sprintf(numstr, "%d", MOVES);
  strcat(fixedMoves, numstr);

  sprintf(numstr, "%d", BOOKS);
  strcat(fixedBooks, numstr);

  sprintf(numstr, "%d", LIVES);
  strcat(fixedLives, numstr);

  // Copy to renderer
  textPosition.x = LVL_X;
  SDL_Surface * surface = TTF_RenderText_Solid(font,
  LVL_TEXT, color);
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
