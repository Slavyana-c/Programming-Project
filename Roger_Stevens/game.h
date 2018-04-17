#include "constants.h"

#ifndef DEF_GAME
#define DEF_GAME

void movePlayer(int map[][MAP_WIDTH_BLOCKS], SDL_Rect *pos, int direction);
void renderText(SDL_Renderer *renderer);
int play(SDL_Renderer *renderer, char fileName[]);

#endif
