/*
game.c
Playing the game
*/

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "globals.h"
#include "constants.h"
#include "files.h"

// Move the player
// Without leaving the map or going through walls
void movePlayer(int map[][MAP_WIDTH_BLOCKS], SDL_Rect *pos, int direction)
{
      switch(direction)
    {
        case UP:
            if (pos->y - 1 < 0) // Don't leave screen
                break;
            if (map[pos->y - 1][pos->x] == WALL) // Don't go through walls
                break;

            pos->y--;
            MOVES++;
            if(map[pos->y][pos->x] == BOOK)
            {
              map[pos->y][pos->x] = EMPTY;
              BOOKS++;
            }
            break;

        case DOWN:
            if (pos->y + 1 > MAP_HEIGHT_BLOCKS)
                break;
            if (map[pos->y + 1][pos->x] == WALL)
                break;

            pos->y++;
            MOVES++;
            if(map[pos->y][pos->x] == BOOK)
            {
              map[pos->y][pos->x] = EMPTY;
              BOOKS++;
            }
            break;

        case LEFT:
            if (pos->x - 1 < 0)
                break;
            if (map[pos->y][pos->x-1] == WALL)
                break;

            pos->x--;
            MOVES++;
            if(map[pos->y][pos->x] == BOOK)
            {
              map[pos->y][pos->x] = EMPTY;
              BOOKS++;
            }
            break;

        case RIGHT:
            if (pos->x + 1 > MAP_WIDTH_BLOCKS)
                break;
            if (map[pos->y][pos->x+1] == WALL)
                break;

            pos->x++;
            MOVES++;
            if(map[pos->y][pos->x] == BOOK)
            {
              map[pos->y][pos->x] = EMPTY;
              BOOKS++;
            }
            break;
    }

}

// Renders the text
void renderText(SDL_Renderer *renderer)
{
  SDL_Rect textPosition;
  char fixedMoves[20] = {0}, fixedBooks[20] = {0},
  fixedLevel[20] = {0}, numstr[5] = {0};

  strcpy(fixedLevel, "Level: ");
  strcpy(fixedMoves, "Moves: ");
  strcpy(fixedBooks, "Books: ");

  // Set text position
  textPosition.y = TEXT_Y;
  textPosition.h = TEXT_H;
  textPosition.w = TEXT_W;

  TTF_Font * font = TTF_OpenFont("fonts/arial.ttf", 25);
  if(!font)
  {
      printf("TTF_OpenFont error: %s\n", TTF_GetError());
  }

  // Set color to white
  SDL_Color color = { 255, 255, 255 };

  // Set the level
  sprintf(numstr, "%d", LVL_NUM);
  strcat(fixedLevel, numstr);

  sprintf(numstr, "%d", MOVES);
  strcat(fixedMoves, numstr);

  sprintf(numstr, "%d", BOOKS);
  strcat(fixedBooks, numstr);

  // Copy to renderer
  textPosition.x = LVL_X;
  SDL_Surface * surface = TTF_RenderText_Solid(font,
  fixedLevel, color);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
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

  TTF_CloseFont(font);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

}

// Returns 1 if you have to continue to the next lvl
int play(SDL_Renderer *renderer, char fileName[])
{
    SDL_Texture *player[4] = {NULL};
    SDL_Texture *wall = NULL, *book = NULL, *playerNow = NULL, *scene = NULL;
    SDL_Rect position, playerPosition, scenePosition;
    int nextLvl = 1, quit = 0, booksLeft = 0, i = 0, j = 0;
    char sceneName[20] = {0};
    SDL_Event event;

    int map[MAP_HEIGHT_BLOCKS][MAP_WIDTH_BLOCKS] = {{0}};

    TTF_Init();

    // Load images
    wall = IMG_LoadTexture(renderer, "images/mur.jpg");
    book = IMG_LoadTexture(renderer, "images/objectif.png");
    player[DOWN] = IMG_LoadTexture(renderer, "images/mario_bas.gif");
    player[LEFT] = IMG_LoadTexture(renderer, "images/mario_gauche.gif");
    player[UP] = IMG_LoadTexture(renderer, "images/mario_haut.gif");
    player[RIGHT] = IMG_LoadTexture(renderer, "images/mario_droite.gif");

    // Set positions
    scenePosition.y = 0;
    scenePosition.x = 0;
    scenePosition.h = SCENE_HEIGHT;
    scenePosition.w = SCENE_WIDTH;

    position.w = BLOCK_SIZE;
    position.h = BLOCK_SIZE;
    playerPosition.w = BLOCK_SIZE;
    playerPosition.h = BLOCK_SIZE;

    playerPosition.x = 0;
    playerPosition.y = 0;

    // Showing the player looking down
    playerNow = player[DOWN];

    // Loading the level
    if (!loadLevel(map, sceneName, fileName))
    {
        printf("%s Problem\n", fileName);
        exit(EXIT_FAILURE);
    }

    // Set the scene
    scene = IMG_LoadTexture(renderer, sceneName);

    // Find the player
    for (i = 0 ; i < MAP_HEIGHT_BLOCKS ; i++)
    {
        for (j = 0 ; j < MAP_WIDTH_BLOCKS ; j++)
        {
            if (map[i][j] == PLAYER)
            {
                playerPosition.x = j;
                playerPosition.y = i;
                map[i][j] = EMPTY;
            }
        }
    }

    // Event loop
    while (!quit)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                nextLvl = 0;
                GAME_MODE = QUIT;
                quit = 1;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        nextLvl = 0;
                        GAME_MODE = MENU;
                        map[playerPosition.y][playerPosition.x] = PLAYER;
                        saveLevel(map, sceneName, "levels/continue.txt");
                        quit = 1;
                        break;

                    case SDLK_UP:
                        playerNow = player[UP];
                        movePlayer(map, &playerPosition, UP);
                        break;

                    case SDLK_DOWN:
                        playerNow = player[DOWN];
                        movePlayer(map, &playerPosition, DOWN);
                        break;

                    case SDLK_RIGHT:
                        playerNow = player[RIGHT];
                        movePlayer(map, &playerPosition, RIGHT);
                        break;

                    case SDLK_LEFT:
                        playerNow = player[LEFT];
                        movePlayer(map, &playerPosition, LEFT);
                        break;
                }
             break;
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, scene, NULL, &scenePosition);
        booksLeft = 0;

        // Render the map
        for (i = 0 ; i < MAP_HEIGHT_BLOCKS ; i++)
        {
            for (j = 0 ; j < MAP_WIDTH_BLOCKS ; j++)
            {
                position.x = j * BLOCK_SIZE;
                position.y = SCENE_HEIGHT + i * BLOCK_SIZE;

                switch(map[i][j])
                {
                    case WALL:
                        SDL_RenderCopy(renderer, wall, NULL, &position);
                        break;
                    case BOOK:
                        SDL_RenderCopy(renderer, book, NULL, &position);
                        booksLeft = 1;
                        break;
                }
            }
        }

        // Level is finished once you collect the books
         if (!booksLeft)
             quit = 1;

        // Render the payer
        position.x = playerPosition.x * BLOCK_SIZE;
        position.y = SCENE_HEIGHT + playerPosition.y * BLOCK_SIZE;
        SDL_RenderCopy(renderer, playerNow, NULL, &position);

        renderText(renderer);
        SDL_RenderPresent(renderer);

    }


    SDL_DestroyTexture(wall);
    SDL_DestroyTexture(book);
    SDL_DestroyTexture(player[UP]);
    SDL_DestroyTexture(player[DOWN]);
    SDL_DestroyTexture(player[LEFT]);
    SDL_DestroyTexture(player[RIGHT]);

    TTF_Quit();
    return nextLvl;
}
