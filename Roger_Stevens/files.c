/*
files.c
Saves and loads levels from files
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "constants.h"
#include "globals.h"

// Load images
void loadImages(SDL_Renderer *renderer, SDL_Texture **player, SDL_Texture **wall, SDL_Texture **book,
   SDL_Texture **enemy, SDL_Texture **tiles, SDL_Texture **shadow)
{
    *book = IMG_LoadTexture(renderer, "images/book.png");
    player[DOWN] = IMG_LoadTexture(renderer, "images/down.png");
    player[LEFT] = IMG_LoadTexture(renderer, "images/left.png");
    player[UP] = IMG_LoadTexture(renderer, "images/up.png");
    player[RIGHT] = IMG_LoadTexture(renderer, "images/right.png");
    *enemy = IMG_LoadTexture(renderer, "images/NETFLIX.jpg");
    *tiles = IMG_LoadTexture(renderer, "images/wtiles.jpg");
    *shadow = IMG_LoadTexture(renderer, "images/shadow_wall.jpg");
    switch (LVL_NUM)
{
      case 0:
      *wall = IMG_LoadTexture(renderer, "images/wall.jpg");
      strcpy(LVL_TEXT, "Custom");
      break;

      case 1:
      *wall = IMG_LoadTexture(renderer, "images/wall.jpg");
      strcpy(LVL_TEXT, "5");
      break;

      case 2:
      *wall = IMG_LoadTexture(renderer, "images/wall.jpg");
      strcpy(LVL_TEXT, "8");
      break;

      case 3:
      *wall = IMG_LoadTexture(renderer, "images/wall.jpg");
      strcpy(LVL_TEXT, "2");
      break;

      case 4:
      *wall = IMG_LoadTexture(renderer, "images/wall.jpg");
      strcpy(LVL_TEXT, "12");
      break;

      case 5:
      *wall = IMG_LoadTexture(renderer, "images/red_wall.jpg");
      strcpy(LVL_TEXT, "-3");
      break;

      case 6:
      *wall = IMG_LoadTexture(renderer, "images/pond_wall.jpg");
      strcpy(LVL_TEXT, "Pond");
      break;

      case 7:
      *wall = IMG_LoadTexture(renderer, "images/lava_wall.jpg");
      strcpy(LVL_TEXT, "-666");
      break;

      case 8:
      *wall = IMG_LoadTexture(renderer, "images/grass_wall.jpg");
      strcpy(LVL_TEXT, "999");
      break;

      case 9:
      *wall = IMG_LoadTexture(renderer, "images/grass_wall.jpg");
      strcpy(LVL_TEXT, "???");
      break;

      case 10:
      *wall = IMG_LoadTexture(renderer, "images/wall.jpg");
      strcpy(LVL_TEXT, "Long room");
      break;
    }



}


void highScore()
{
    int bestMoves, bestBooks;
      FILE* file = NULL;
      file = fopen("levels/scores.txt", "r");
      if (file == NULL)
      {
          printf("Can't read file \n");
          return;
      }

      fscanf(file,"%d %d", &bestMoves, &bestBooks);
      if(GAME_MODE == WIN && LVL_NUM != 0)
      {
        if(MOVES < bestMoves) bestMoves = MOVES;
        bestBooks = BOOKS;
      }
      else if(GAME_MODE == LOSE && LVL_NUM != 0)
      {
        if(BOOKS > bestBooks) bestBooks = BOOKS;
      }

      fclose(file);


      file = fopen("levels/scores.txt", "w");
      if (file == NULL)
      {
          printf("Can't write in file\n");
          return;
      }


      //showScore(bestBooks, bestMoves);
      printf("saved score\n");
      fprintf(file, "%d %d", bestMoves, bestBooks);

      fclose(file);

}

// Load the level, return 1 if successful
int loadLevel(int level[][MAP_WIDTH_BLOCKS], char sceneName[], char fileName[])
{
    FILE* file = NULL;
    int fileData[MAP_HEIGHT_BLOCKS * MAP_WIDTH_BLOCKS] = {0};
    int count = 0;
    int i, j;

    printf("Loading file %s\n", fileName);
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Can't read file \n");
        return 0;
    }

    // Get the scene name
    fgets(sceneName, 100, file);
    sceneName[strcspn(sceneName, "\r\n")] = 0;

    // Get level and progress
    if(GAME_MODE == PLAY) fscanf(file,"%d", &LVL_NUM);
    else fscanf(file,"%d %d %d %d", &LVL_NUM, &LIVES, &MOVES, &BOOKS);

    // Get map data
    while(!feof(file))
    {
        fscanf(file,"%d", &fileData[count]);
        count++;
    }

    fclose(file);

    // Put data in map
    for (i = 0 ; i < MAP_HEIGHT_BLOCKS ; i++)
    {
        for (j = 0 ; j < MAP_WIDTH_BLOCKS ; j++)
        {
                level[i][j] = fileData[(i * MAP_WIDTH_BLOCKS) + j];
        }
    }

    return 1;
}

// Save the level, return 1 if successful
int saveLevel(int level[][MAP_WIDTH_BLOCKS], char sceneName[], char fileName[])
{

  printf("Saving file %s\n", fileName);
    FILE *file = fopen(fileName, "w");
    if (file == NULL)
    {
        printf("Can't write in file\n");
        return 0;
    }

    // Save all data about the level
    fprintf(file, "%s\n", sceneName);
    fprintf(file, "%d %d %d %d\n", LVL_NUM, LIVES, MOVES, BOOKS);
    for (int i = 0 ; i < 16 ; i++)
    {
        for (int j = 0 ; j < 20; j++)
        {
            fprintf(file, "%d ", level[i][j]);
        }
        fprintf(file, "%c", '\n');
    }

    fclose(file);
    return 1;

  return 0;

}
