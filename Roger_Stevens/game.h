#include "constants.h"

#ifndef DEF_GAME
#define DEF_GAME

void playerDead(SDL_Renderer *renderer, SDL_Rect pos, SDL_Texture *playerNow, SDL_Texture *tiles);
void movePlayer(int map[][MAP_WIDTH_BLOCKS], SDL_Rect *pos, int direction);
int play(SDL_Renderer *renderer, char fileName[]);

#endif
