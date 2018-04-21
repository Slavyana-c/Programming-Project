/*
files.h
Prototypes of files.c
*/

#include <SDL2/SDL.h>
#include "constants.h"

#ifndef DEF_FILES
#define DEF_FILES

void loadImages(SDL_Renderer *renderer, SDL_Texture **player, SDL_Texture **wall, SDL_Texture **book,
   SDL_Texture **enemy, SDL_Texture **tiles, SDL_Texture **shadow);
    int loadLevel(int level[][MAP_WIDTH_BLOCKS], char sceneName[], char fileName[]);
    int saveLevel(int level[][MAP_WIDTH_BLOCKS], char sceneName[], char fileName[]);
    void highScore();

#endif
