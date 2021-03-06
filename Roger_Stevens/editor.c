/*
editor.c
Opens the edit custom level mode
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "constants.h"
#include "editor.h"
#include "files.h"
#include "globals.h"
#include "game.h"
#include "texts.h"

// Edits the level
void editor(SDL_Renderer *renderer)
{
  SDL_Texture *wall = NULL, *book = NULL, *player = NULL, *scene = NULL, *enemy = NULL, *tiles = NULL, *shadow = NULL;
  SDL_Rect position, scenePosition, mousePosition;
  SDL_Event event;
  char sceneName[20];
  char fileName[20];

  int quit = 0, i = 0, j = 0, leftClick = 0, rightClick = 0;
  int map[MAP_HEIGHT_BLOCKS][MAP_WIDTH_BLOCKS] = {{0}};
  int currentObject = WALL;

  // Load images
  book = IMG_LoadTexture(renderer, "images/book.png");
  player= IMG_LoadTexture(renderer, "images/down.png");
  enemy = IMG_LoadTexture(renderer, "images/NETFLIX.png");
  tiles = IMG_LoadTexture(renderer, "images/tiles3.jpg");
  wall = IMG_LoadTexture(renderer, "images/wall.jpg");
  shadow = IMG_LoadTexture(renderer, "images/shadow_wall.jpg");

  strcpy(fileName, "levels/custom.txt");

  TTF_Init();
  TTF_Font * font = TTF_OpenFont("fonts/arial.ttf", 50);

  // Set positions
  scenePosition.y = 0;
  scenePosition.x = 0;
  scenePosition.h = SCENE_HEIGHT;
  scenePosition.w = SCENE_WIDTH;

  mousePosition.w = BLOCK_SIZE;
  mousePosition.h = BLOCK_SIZE;
  position.w = BLOCK_SIZE;
  position.h = BLOCK_SIZE;

  // Load level
  if (!loadLevel(map, sceneName, fileName))
  {
    printf("%s Problem\n", fileName);
    exit(EXIT_FAILURE);
  }

  scene = IMG_LoadTexture(renderer, sceneName);

  // Event loop
  while (!quit)
  {
    SDL_PollEvent(&event);
    switch(event.type)
    {
      case SDL_QUIT:
      GAME_MODE = QUIT;
      quit = 1;
      break;

      // Add/destroy object on map
      case SDL_MOUSEBUTTONDOWN:
      if (event.button.button == SDL_BUTTON_LEFT)
      {
        if((event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE >= 0 && (event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE < MAP_HEIGHT_BLOCKS)
        {
          map[(event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE][event.button.x /BLOCK_SIZE] = currentObject;
        }

        leftClick = 1;
      }

      else if (event.button.button == SDL_BUTTON_RIGHT)
      {
        if((event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE > 0 && (event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE < MAP_HEIGHT_BLOCKS)
        {
          map[(event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE][event.button.x /BLOCK_SIZE] = EMPTY;
        }

        rightClick = 1;
      }
      break;

      // Stop putting/destroying objects
      case SDL_MOUSEBUTTONUP:
      if (event.button.button == SDL_BUTTON_LEFT)
      leftClick = 0;
      else if (event.button.button == SDL_BUTTON_RIGHT)
      rightClick = 0;
      break;

      // Calculate mouse position and put/destroy object on map
      // Wherever the mouse moves
      case SDL_MOUSEMOTION:
      mousePosition.x = event.motion.x - 20;
      mousePosition.y = event.motion.y - 20;
      if (leftClick)
      {
        if((event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE >= 0 && (event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE < MAP_HEIGHT_BLOCKS)
        {
          map[(event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE][event.button.x /BLOCK_SIZE] = currentObject;
        }
      }
      else if (rightClick)
      {
        if((event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE >= 0 && (event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE < MAP_HEIGHT_BLOCKS)
        {
          map[(event.motion.y - SCENE_HEIGHT) / BLOCK_SIZE][event.button.x /BLOCK_SIZE] = EMPTY;
        }
      }
      break;

      // Select the different objects
      case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
      {
        case SDLK_ESCAPE:
        quit = 1;
        GAME_MODE = MENU;
        break;

        case SDLK_1:
        currentObject = WALL;
        break;

        case SDLK_2:
        currentObject = BOOK;
        break;

        case SDLK_3:
        currentObject = ENEMY;
        break;

        case SDLK_4:
        currentObject = PLAYER;
        break;

        case SDLK_s:
        saveLevel(map, sceneName, fileName);
        savedMessage(renderer, font);
        break;
      }
      break;
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, scene, NULL, &scenePosition);

    // Render map
    for (i = 0 ; i < MAP_HEIGHT_BLOCKS ; i++)
    {
      for (j = 0 ; j < MAP_WIDTH_BLOCKS ; j++)
      {
        position.x = j * BLOCK_SIZE;
        position.y = SCENE_HEIGHT + (i * BLOCK_SIZE);

        switch(map[i][j])
        {
          case WALL:
          if((i != MAP_HEIGHT_BLOCKS - 1)
          && (map[i + 1][j] != WALL))
          {
            SDL_RenderCopy(renderer, shadow, NULL, &position);
          }
          else SDL_RenderCopy(renderer, wall, NULL, &position);
          break;

          case BOOK:
          SDL_RenderCopy(renderer, tiles, NULL, &position);
          SDL_RenderCopy(renderer, book, NULL, &position);
          break;

          case ENEMY:
          SDL_RenderCopy(renderer, tiles, NULL, &position);
          SDL_RenderCopy(renderer, enemy, NULL, &position);
          break;

          case PLAYER:
          SDL_RenderCopy(renderer, tiles, NULL, &position);
          SDL_RenderCopy(renderer, player, NULL, &position);
          break;

          case EMPTY:
          SDL_RenderCopy(renderer, tiles, NULL, &position);
        }
      }
    }

    // Render mouse block
    switch(currentObject)
    {
      case WALL:
      SDL_RenderCopy(renderer, wall, NULL, &mousePosition);
      break;

      case BOOK:
      SDL_RenderCopy(renderer, book, NULL, &mousePosition);
      break;

      case ENEMY:
      SDL_RenderCopy(renderer, enemy, NULL, &mousePosition);
      break;
      case PLAYER:
      SDL_RenderCopy(renderer, player, NULL, &mousePosition);
      break;
    }
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(wall);
  SDL_DestroyTexture(book);
  SDL_DestroyTexture(player);
  SDL_DestroyTexture(enemy);
  SDL_DestroyTexture(tiles);
  SDL_DestroyTexture(shadow);
  TTF_Quit();
}
