#include <stdlib.h>
#include <SDL2/SDL.h>

#include "constants.h"
#include "globals.h"

void option(SDL_Renderer *renderer)
{
    char path[20], fileName[20], numstr[2];

    switch(GAME_MODE)
    {
        case PLAY:
          printf("Startig new game.\n");

          // Zero the score
          MOVES = 0;
          BOOKS = 0;

          // Loop through the levels
          for (int i = 1; i <= ALL_LEVELS; i++)
          {
              strcpy(path, "levels/lvl");
              strcpy(fileName, path);
              sprintf(numstr, "%d", i);
              strcat(fileName, numstr);
              strcat(fileName, ".txt");
            //if(!game(renderer, fileName, option)) break;
          }

          break;

        case CONTINUE:
            printf("Loading saved game.\n");
            strcpy(fileName, "continue.txt");
            //if(!game(renderer, fileName, option)) break;
            LVL_NUM++;
            for (int i = LVL_NUM; i <= ALL_LEVELS; i++)
            {
                GAME_MODE = PLAY;
                strcpy(path, "levels/lvl");
                strcpy(fileName, path);
                sprintf(numstr, "%d", i);
                strcat(fileName, numstr);
                strcat(fileName, ".txt");
                //if(!game(renderer, fileName, option)) break;
            }

            break;

        case 3:
            printf("Edit custom level.\n");
            //strcpy(fileName, "custom.txt");
            //editor(renderer);
            break;


        case 4:
            printf("Play custom level.\n");
            //strcpy(fileName, "custom.txt");
            strcpy(fileName, "custom.txt");
            //if(!game(renderer, fileName, option)) break;
            break;
    }
}
