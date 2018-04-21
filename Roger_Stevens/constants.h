/*
constants.h
Defines the constants for the whole program
*/

#ifndef DEF_CONSTANTS
#define DEF_CONSTANTS

    // Size of a block in pixels
    #define BLOCK_SIZE          42

    // Window size
    #define WIDTH_IN_BLOCKS     20
    #define HEIGHT_IN_BLOCKS    19
    #define WINDOW_WIDTH        BLOCK_SIZE * WIDTH_IN_BLOCKS
    #define WINDOW_HEIGHT       BLOCK_SIZE * HEIGHT_IN_BLOCKS

    // Scene size
    #define SCENE_WIDTH         WIDTH_IN_BLOCKS * BLOCK_SIZE
    #define SCENE_HEIGHT        2 * BLOCK_SIZE

    // Score bar size
    #define BAR_WIDTH           WIDTH_IN_BLOCKS * BLOCK_SIZE
    #define BAR_HEIGHT          BLOCK_SIZE

    // Text position
    #define TEXT_Y              WINDOW_HEIGHT - 28
    #define TEXT_H              20
    #define TEXT_W              80

    #define LVL_X               20
    #define LIVES_X             200
    #define MOVES_X             600
    #define BOOKS_X             700
    #define SAVE_X              WINDOW_WIDTH / 2


    #define SCORE_H             40
    #define SCORE_W             150
    #define HIGH_SCORE_W        250
    #define SCORE_X             70
    #define HIGH_SCORE_X        520
    #define SCORE_MOVES_Y       650
    #define SCORE_BOOKS_Y       700

    // Map size in blocks
    #define MAP_WIDTH_BLOCKS    WIDTH_IN_BLOCKS
    #define MAP_HEIGHT_BLOCKS   (HEIGHT_IN_BLOCKS - 3)

    // Levels
    #define ALL_LEVELS          10

    // Useful enumerations
    enum {UP, DOWN, LEFT, RIGHT};
    enum {EMPTY, WALL, BOOK, ENEMY, PLAYER};
    enum {MENU, PLAY, CONTINUE, EDIT, CUSTOM, QUIT, WIN, LOSE};

#endif
