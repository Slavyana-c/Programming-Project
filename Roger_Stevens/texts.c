/*
texts.c
Renders the text on the screen
*/

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "globals.h"
#include "constants.h"
#include "files.h"

// Shows the score at the end of the game
void showScore(SDL_Renderer *renderer, TTF_Font *font, int bestMoves, int bestBooks)
{
  SDL_Rect textPosition;

  // Text position
  textPosition.y;
  textPosition.h = SCORE_H;
  textPosition.w = SCORE_W;

  char booksText[20] = "Books: ";
  char bestBooksText[20] = "High score: ";
  char movesText[20] = "Moves: ";
  char bestMovesText[20] = "High score: " ;
  char numstr[5];
  SDL_Surface * surface = NULL;
  SDL_Texture * texture = NULL;

  // Set color to white
  SDL_Color color = { 255, 255, 255 };

  // Show the moves made if the game is won
  if(GAME_MODE == WIN)
  {
    textPosition.y = SCORE_MOVES_Y;
    textPosition.x = SCORE_X;
    sprintf(numstr, "%d", MOVES);
    strcat(movesText, numstr);

    surface = TTF_RenderText_Solid(font,movesText, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &textPosition);

    // Show high score if it's not a custom level
    if(LVL_NUM != 0)
    {
      textPosition.x = HIGH_SCORE_X;
      textPosition.w = HIGH_SCORE_W;

      sprintf(numstr, "%d", bestMoves);
      strcat(bestMovesText, numstr);
      surface = TTF_RenderText_Solid(font, bestMovesText, color);
      texture = SDL_CreateTextureFromSurface(renderer, surface);
      SDL_RenderCopy(renderer, texture, NULL, &textPosition);
    }
  }

  textPosition.y = SCORE_BOOKS_Y;
  textPosition.x = SCORE_X;
  textPosition.w = SCORE_W;
  sprintf(numstr, "%d", BOOKS);
  strcat(booksText, numstr);

  surface = TTF_RenderText_Solid(font,booksText, color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_RenderCopy(renderer, texture, NULL, &textPosition);

  // Show high score if it's not a custom level
  if(LVL_NUM != 0)
  {
    textPosition.x = HIGH_SCORE_X;
    textPosition.w = HIGH_SCORE_W;
    sprintf(numstr, "%d", bestBooks);
    strcat(bestBooksText, numstr);
    surface = TTF_RenderText_Solid(font,bestBooksText, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &textPosition);
  }

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}

// Writes saving... when the game is saved
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
  SDL_Surface * surface = TTF_RenderText_Solid(font,saved, color);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_RenderCopy(renderer, texture, NULL, &textPosition);
  SDL_RenderPresent(renderer);
  SDL_Delay(500);

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}

// Renders the text at the bottom of the level
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

  // Set the strings
  sprintf(numstr, "%d", MOVES);
  strcat(fixedMoves, numstr);

  sprintf(numstr, "%d", BOOKS);
  strcat(fixedBooks, numstr);

  sprintf(numstr, "%d", LIVES);
  strcat(fixedLives, numstr);

  // Copy to renderer
  textPosition.x = LVL_X;
  SDL_Surface * surface = TTF_RenderText_Solid(font, LVL_TEXT, color);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_RenderCopy(renderer, texture, NULL, &textPosition);

  textPosition.x = LIVES_X;
  surface = TTF_RenderText_Solid(font,fixedLives, color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_RenderCopy(renderer, texture, NULL, &textPosition);

  textPosition.x = MOVES_X;
  surface = TTF_RenderText_Solid(font,fixedMoves, color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_RenderCopy(renderer, texture, NULL, &textPosition);

  textPosition.x = BOOKS_X;
  surface = TTF_RenderText_Solid(font,fixedBooks, color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_RenderCopy(renderer, texture, NULL, &textPosition);

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}
