#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "constants.h"
#include "globals.h"

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

    if(GAME_MODE == PLAY) fscanf(file,"%d", &LVL_NUM);
    else fscanf(file,"%d %d %d", &LVL_NUM, &MOVES, &BOOKS);

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
    fprintf(file, "%d %d %d\n", LVL_NUM, MOVES, BOOKS);
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
