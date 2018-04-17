#include <SDL2/SDL.h>
#include "constants.h"

#ifndef DEF_FILES
#define DEF_FILES

    int loadLevel(int level[][MAP_WIDTH_BLOCKS], char sceneName[], char fileName[]);
    int saveLevel(int level[][MAP_WIDTH_BLOCKS], char sceneName[], char fileName[]);

#endif
